/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:23 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 18:27:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMethods.hpp"
#include <iostream>
#include "utils.hpp"
#include "ErrorDefault.hpp"
#include "ReasonPhrase.hpp"
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
	_reasonPhrase = "";
	_contentType = "";
	_bufferBody = "";
	_pathTraslated = "";
	std::time_t		time = 0;
	_http.setHeaders("Server", "MyServer");
	_http.setHeaders("Date", getCurrentDateTime(time));
	_http.setHeaders("Connection", "close");
}

HTTP AMethods::getHTTP(){	
	_http.setStatusResponse(_statusCode, _reasonPhrase);
	_http.setHeaders("Content-Type", _contentType);
 	_http.setBody(_bufferBody);	
	return _http;
}	

void	AMethods::processReturnDirective(){
	if (not _returnIndex.getReturnAddr().empty()){
		_http.setHeaders("Location", _returnIndex.getReturnAddr());
		_statusCode = _returnIndex.getReturnStatus();
		_reasonPhrase = ReasonPhrase::getPhrase(_statusCode);
	}
	else
		processError(_returnIndex.getReturnStatus());
}

void	AMethods::addResponseBody(std::string fileName){
	DIR	*directory;

	directory = opendir(fileName.c_str());
	if (directory != NULL){
		if (not _index.empty())
			_bufferBody = GetFile::getBufferFile(fileName + _index.getIndex());
		else if (_index.empty() && (not _autoIndex.empty() && _autoIndex.getAutoIndexBool()))
			_bufferBody = GetFile::getBufferDirectory(directory, fileName);
		else
			_bufferBody.clear();
		closedir(directory);
	}
	else
		_bufferBody = GetFile::getBufferFile(fileName);
	if(_bufferBody.empty())
		processError(404);
	else{
		_statusCode = 200;
		_reasonPhrase = ReasonPhrase::getPhrase(200);
		_contentType = getMime(_path_cgi);
	}	
}

void	AMethods::processError(int statusError){
	_bufferBody.clear();
	if (not _errorPage.getErrorPage(statusError).empty())
		_bufferBody = GetFile::getBufferFile(_root.getRoot() + _errorPage.getErrorPage(statusError));
	if(_bufferBody.empty())
		_bufferBody = ErrorDefault::getHTML(statusError);
	_statusCode = statusError;
	_reasonPhrase = ReasonPhrase::getPhrase(statusError);	
	_contentType = getMime(_path_cgi);
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

void	AMethods::processFile(){
	std::string		path;
	std::string		buffer;
	std::string		file;

	file = getFile(_path_html);
	path = _root.getRoot();
	path += file;
	if (file.size() == 1 && file[0] == '/'){
		path += _index.getIndex();
	}
	addResponseBody(path);
}

int AMethods::getErrorValue(){
	std::string statusError = "STATUS CODE: ";
	std::string	value;
	std::size_t	posBegin = statusError.length();
	std::size_t	posEnd = _bufferBody.length() - posBegin;

	if (_bufferBody.empty())
		return -1;
	value = _bufferBody.substr(posBegin, posEnd);
	trim(value);
	return toInt(value);
}