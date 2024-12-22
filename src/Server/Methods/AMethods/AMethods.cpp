/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:51:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMethods.hpp"
#include <iostream>
#include "utils.hpp"
#include "ErrorDefault.hpp"
#include "unistd.h"
#include <fcntl.h>

void	AMethods::selectDirectives(Server &server, Request &request)
{
	DataLocation	dataLocation;
	DataServer		dataServer;
	
	dataServer = server.getDataServerOBJ();
	dataLocation = findLocation(server, request);
	if (not dataLocation.empty())
	{
		_root = dataLocation.getRootOBJ();
		_index = dataLocation.getIndexOBJ();
		_errorPage = dataLocation.getErrorPageOBJ();
		_maxBodySize = dataLocation.getMaxBodySizeOBJ();
		_autoIndex = dataLocation.getAutoIndexOBJ();
		_allowMethods = dataLocation.getAllowedMethodOBJ();
		_returnIndex= dataLocation.getReturnOBJ();
	}
	if (_root.empty())
		_root = dataServer.getRootOBJ();
	if (_index.empty())
		_index = dataServer.getIndexOBJ();
	if (_errorPage.empty())
		_errorPage = dataServer.getErrorPageOBJ();
	if (_maxBodySize.empty())
		_errorPage = dataServer.getErrorPageOBJ();
}
 

HTTP AMethods::getHTTP()
{	
	_http.setStatusResponse(_statusCode, _statusMensagen);
	_http.setHeaders("Content-Type", _contentType);
 	_http.setBody(_bufferBody);	
	return _http;
}	


bool	AMethods::errorRequest(Server &server, Request &request)
{
	int	error = 0;

	error = request.getParserError();
	if(error == 0)
		return false;
	_statusCode = error;
	_statusMensagen = "not ok";
	_contentType = "text/html";
	_bufferBody = server.getErrorPage(error);
	if (_bufferBody.empty())
		_bufferBody = ErrorDefault::getErrorDefault(error);
	return true;
}

std::string	AMethods::getBufferFile(std::string fileName)
{
	std::ifstream file(fileName.c_str(), std::ios::in | std::ios::binary);

	if(!file)
	{
		_statusCode = 200;
		_statusMensagen = "ok";	
		return std::string();
	}
	_statusCode = 200;
	_statusMensagen = "ok";
	std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	return buffer;
}

std::string	isDirectory(std::string fileName)
{
	int fd;

	fd = open(fileName.c_str(),  O_DIRECTORY);
	if (fd != -1)
	{
		std::cout << "Is Directory\n";
	} 
	return std::string();
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


AMethods::~AMethods(){}
AMethods::AMethods()
{
	_statusCode = 0;
	_statusMensagen = "";
	_contentType = "";
	_bufferBody = "";
	std::time_t		time = 0;
	_http.setHeaders("Server", "MyServer");
	_http.setHeaders("Date", getCurrentDateTime(time));
	_http.setHeaders("Connection", "close");
}