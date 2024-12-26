/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/24 13:16:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMethods.hpp"
#include <iostream>
#include "utils.hpp"
#include "ErrorDefault.hpp"
#include "unistd.h"
#include <fcntl.h>
#include "FindLocation.hpp"
#include "GetFile.hpp"

AMethods::~AMethods(){}

AMethods::AMethods(){
	_statusCode = 0;
	_statusMensagen = "";
	_contentType = "";
	_bufferBody = "";
	std::time_t		time = 0;
	_http.setHeaders("Server", "MyServer");
	_http.setHeaders("Date", getCurrentDateTime(time));
	_http.setHeaders("Connection", "close");
}

DataLocation	AMethods::findDataLocation(Server &server, Request &request){
	return FindLocation::findLocation(server, request);
}

void	AMethods::selectDirectives(Server &server, Request &request)
{
	DataLocation	dataLocation;
	DataServer		dataServer;

	dataLocation = findDataLocation(server, request);
	dataServer = server.getDataServerOBJ();
	addGlobalDirectives(dataServer);
	if (not dataLocation.empty())
		addLocationDirectives(dataLocation);
}

void	AMethods::addGlobalDirectives(DataServer dataServer){
	_root = dataServer.getRootOBJ();
	_index = dataServer.getIndexOBJ();
	_errorPage = dataServer.getErrorPageOBJ();
	_errorPage = dataServer.getErrorPageOBJ();
}

void	AMethods::addLocationDirectives(DataLocation dataLocation){
	_index = dataLocation.getIndexOBJ();
	_allowMethods = dataLocation.getAllowedMethodOBJ();
	_returnIndex = dataLocation.getReturnOBJ();
	_autoIndex = dataLocation.getAutoIndexOBJ();
	if (not dataLocation.getRootOBJ().empty())
		_root = dataLocation.getRootOBJ();
	if (not dataLocation.getErrorPageOBJ().empty())
		_errorPage = dataLocation.getErrorPageOBJ();
	if (not dataLocation.getMaxBodySizeOBJ().empty())
		_maxBodySize = dataLocation.getMaxBodySizeOBJ();
}

HTTP AMethods::getHTTP()
{	
	_http.setStatusResponse(_statusCode, _statusMensagen);
	_http.setHeaders("Content-Type", _contentType);
 	_http.setBody(_bufferBody);	
	return _http;
}	

bool	AMethods::errorRequest(Request &request)
{
	int	error = 0;

	error = request.getParserError();
	if(error == 0)
		return false;
	_statusCode = error;
	_statusMensagen = "not ok";
	_contentType = "text/html";
	_bufferBody = _errorPage.getErrorPage(error);
	if (_bufferBody.empty())
		_bufferBody = ErrorDefault::getErrorDefault(error);
	return true;
}

std::string AMethods::getFile(std::string url){
	std::size_t index;
	std::string file;

	if (url.size() == 1 && url[0] == '/')
		return url += _index.getIndex();
	index = url.size();
	while (index != 0)
	{
		if (url[index] == '/')
			break ;
		index--;
	}
	index++;
	while (index != url.size())
	{
		file += url[index];
		index++;
	}
	return file;
}

std::string	AMethods::getBufferFile(std::string fileName){
	std::string buffer;
	DIR *directory;

	directory = opendir(fileName.c_str());
	if (directory != NULL){
		if (not _index.empty())
			buffer = GetFile::getBufferFile(fileName + _index.getIndex());
		else if (_index.empty() && (not _autoIndex.empty() && _autoIndex.getAutoIndexBool()))
			buffer = GetFile::getBufferDirectory(directory, fileName);
		else
			buffer.clear();
		closedir(directory);
	}
	else
		buffer = GetFile::getBufferFile(fileName);
	if(buffer.empty())
	{
		_statusCode = 404;
		_statusMensagen = "not ok";	
		return std::string();
	}
	_statusCode = 200;
	_statusMensagen = "ok";
	return buffer;
}
