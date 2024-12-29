/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/29 19:11:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get.hpp"
#include "ErrorDefault.hpp"

Get::Get(): AMethods(){}

Get::~Get(){}

HTTP	Get::createHTTP(Server &server, Request &request){
	std::string		path;
	std::string		buffer;
	std::string		file;
	
	if (not (buffer = validHeaders(request)).empty()){
		_contentType = server.getMime(request.getPath());
		_bufferBody = buffer;
		return getHTTP();
	}
	if (request.getPath().find("/cgi/") != std::string::npos){
		_bufferBody = commonGatewayInterface(server);
		if (not _bufferBody.empty()){
			_statusCode = 200;
			_statusMensagen = "ok";
			return getHTTP();
		}
	}
	file = getFile(_path_html);
	path = _root.getRoot();
	path += file;
	if (file.size() == 1 && file[0] == '/'){
		path += _index.getIndex();
	}
	buffer = getBufferFile(path);
	if (buffer.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	_contentType = server.getMime(request.getPath());
	_bufferBody = buffer;
	return getHTTP();	
}

std::string	Get::validHeaders(Request &request){
	std::list<std::string>	headers;
	std::string				buffer;

	headers = request.getHeader("Content-Length");
	if (not headers.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	headers = request.getHeader("Content-Type");
	if (not headers.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	return buffer;
}
