/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/31 12:41:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get.hpp"
#include "ErrorDefault.hpp"

Get::Get(): AMethods(){}

Get::~Get(){}

HTTP	Get::createHTTP(){
	if (not _path_html.empty()){
		processFILE();
		return getHTTP();
	}
	if (_path_html.empty() && not _path_cgi.empty()){
		Get::processCGI();
		return getHTTP();
	}
	processError(404);
	return getHTTP();
}

void	Get::processFILE(){
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

void	Get::processCGI(){
	_bufferBody = commonGatewayInterface();
	if (not _bufferBody.empty()){
		_statusCode = 200;
		_statusMensagen = "ok";
	}
}




/* 	if (not (buffer = validHeaders(request)).empty()){
		_contentType = server.getMime(request.getPath());
		_bufferBody = buffer;
		return getHTTP();
	} */