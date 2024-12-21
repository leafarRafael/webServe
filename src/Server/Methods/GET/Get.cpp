/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 12:08:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get.hpp"
#include "ErrorDefault.hpp"

Get::Get(): AMethods(){ _method = "GET"; }

Get::~Get(){}

HTTP	Get::createHTTP(Server &server, Request &request){
	std::string	path;
	std::string	buffer;
	DataLocation location;

	location = findLocation(server, request);
	if (not location.empty()){
		std::cout << "create - Location.empty() = " << location.empty() << "\n";
		path = server.getRoot();
		path += request.getPath();
		buffer = getBufferFile(path);
		if (buffer.empty()){
			buffer = getBufferFile(server.getRoot() + server.getErrorPage(404));
			if(buffer.empty())
				buffer = ErrorDefault::getErrorDefault(404);
		}
		_contentType = "image/png";
		_bufferBody = buffer;
		return getHTTP();
	}else{
		path = server.getRoot();
		path += request.getPath();
		path += server.getIndex();
		std::cout << "Path: " << path << "\n";
		buffer = getBufferFile(path);
		if (buffer.empty()){
			buffer = getBufferFile(server.getRoot() + server.getErrorPage(404));
			if(buffer.empty())
				buffer = ErrorDefault::getErrorDefault(404);
		}
		_contentType = request.getHeader("Accept").front();
		_bufferBody = buffer;
		return getHTTP();		
	}
	return HTTP();
}

