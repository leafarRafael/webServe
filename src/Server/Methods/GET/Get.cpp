/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:47:58 by rbutzke          ###   ########.fr       */
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