/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 13:34:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get.hpp"
#include "ErrorDefault.hpp"

Get::Get(): AMethods(){}

Get::~Get(){}

#include "CGI.hpp"

HTTP	Get::createHTTP(Server &server, Request &request){
	std::string		path;
	std::string		buffer;
	std::string		file;
	CGI cgi;

/* 	cgi.commonGatewayInterface(server, request); */

	std::cout << "Headers:\n" << request.getHeader("Content-Type").front()<< "\n\n\n";
	std::cout << request.getBody()->getDataBody().front().getContent();
	
/* 	if (not (buffer = validHeaders(request)).empty()){
		_contentType = server.getMime(request.getPath());
		_bufferBody = buffer;
		return getHTTP();
	} */

	file = getFile(request.getPath());
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

	buffer.clear();
	headers = request.getHeader("Content-Length");
	if (not headers.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	headers = request.getHeader("index/RequisicaoChunked");
	if (not headers.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	return buffer;
}
