/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Post.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/31 12:41:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Post.hpp"
#include "ErrorDefault.hpp"

Post::Post(): AMethods(){}

Post::~Post(){}

HTTP	Post::createHTTP(){
	if (not _path_cgi.empty()){
		_bufferBody = commonGatewayInterface();
		if (_bufferBody == "timeOut")
			processError(402);
		if (_bufferBody.find("204 No Content") != std::string::npos){
			_bufferBody.empty();
			_statusCode = 204;
			_statusMensagen = "No Content";
			return getHTTP();
		}
	}
	if (not _path_html.empty()){
		processFILE();
		return getHTTP();	
	}
	processError(404);
	return getHTTP();
}

void	Post::processFILE(){
	std::string		path;
	std::string		buffer;
	std::string		file;

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
	_contentType = getMime(_path_html);
	_bufferBody = buffer;
}

void	Post::processCGI(){
	_bufferBody = commonGatewayInterface();
	if (not _bufferBody.empty()){
		_statusCode = 200;
		_statusMensagen = "ok";
	}
}
