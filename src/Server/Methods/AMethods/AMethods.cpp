/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:23 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 16:49:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMethods.hpp"
#include <iostream>
#include "utils.hpp"
#include "ErrorDefault.hpp"
#include "unistd.h"
#include <fcntl.h>
#include "GetFile.hpp"

#include "FindLocation.hpp"

AMethods::~AMethods(){}

void	AMethods::setCGI(Server &server){
	setPathTraslated(server);
	if (not _path_cgi.empty()){
		DataLocation location = FindLocation::findLocation(server, _path_cgi);
		if (not location.empty())
			_pathCGITraslated = location.getRoot() + getFile(_path_cgi);
		else
			_pathCGITraslated = server.getDataServerOBJ().getRoot() + getFile(_path_cgi);
	}
	_cgi.setPathCGI(_pathCGITraslated);
	_cgi.setPathTraslated(_pathTraslated);
	_cgi.setPathInfo(_path_info);
	_cgi.setQueryString(_query_string);
	_cgi.setRequestMethod(_method);
	_cgi.setBody(_body);
	_cgi.setContentLength(_content_length);
	_cgi.setContentType(_content_type);
	_cgi.setHTTPVersion(_http_version);
	_cgi.setServerName(server.getDataServerOBJ().getServerName());
}

std::string		AMethods::commonGatewayInterface(){
	return _cgi.commonGatewayInterface();
}

void	AMethods::setPathTraslated(Server &server){
	if (not _path_info.empty()){
		DataLocation location = FindLocation::findLocation(server, _path_info);
		if (not location.empty())
			_pathTraslated = location.getRoot();
		else
			_pathTraslated = server.getDataServerOBJ().getRoot() + _path_info;			
	}
	if (_pathTraslated.empty()){
		DataLocation location = FindLocation::findLocation(server, _path_html);
		if (not location.empty())
			_pathTraslated = location.getRoot();
		else
			_pathTraslated = server.getDataServerOBJ().getRoot() + _path_info;			
	}	
}


AMethods::AMethods() : DataRequest(){
	_statusCode = 0;
	_statusMensagen = "";
	_contentType = "";
	_bufferBody = "";
	_pathTraslated = "";
	std::time_t		time = 0;
	_http.setHeaders("Server", "MyServer");
	_http.setHeaders("Date", getCurrentDateTime(time));
	_http.setHeaders("Connection", "close");
}

HTTP AMethods::getHTTP(){	
	_http.setStatusResponse(_statusCode, _statusMensagen);
	_http.setHeaders("Content-Type", _contentType);
 	_http.setBody(_bufferBody);	
	return _http;
}	

bool	AMethods::errorRequest(Request &request){
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

bool	AMethods::isReturnDirective(){
	if(_returnIndex.empty())
		return false;
	if (not _returnIndex.getReturnAddr().empty()){
		_http.setHeaders("Location", _returnIndex.getReturnAddr());
		_statusMensagen = "Moved Permanently";
		_statusCode = _returnIndex.getReturnStatus();
		
	}
	else{
		processError(_returnIndex.getReturnStatus());
		_statusCode = 404;
		_statusMensagen = "not ok";	
	}
	return true;
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

std::string AMethods::getFile(std::string url){
	std::size_t	index;
	std::string	file;
	
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
	while (index < url.size())
	{
		file += url[index];
		index++;
	}
	return file;
}

void	AMethods::setAtributes(Server &server, Request &request){
	setDateRequest(request);
	selectDirectives(server, request);
	setCGI(server);
}

std::string		AMethods::getMime(std::string path){
	return _mimes.getMime(path);
}

void	AMethods::processError(int statusError){
	std::string buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(statusError));
	if(buffer.empty())
		buffer = ErrorDefault::getErrorDefault(statusError);
	_contentType = getMime(_path_cgi);
	_bufferBody = buffer;
}