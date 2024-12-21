/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 10:31:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMethods.hpp"
#include <iostream>
#include "utils.hpp"
#include "ErrorDefault.hpp"


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

void AMethods::name(){
	std::cout << _method << "\n";
}

HTTP AMethods::getHTTP(){	
	_http.setStatusResponse(_statusCode, _statusMensagen);
	_http.setHeaders("Content-Type", _contentType);
 	_http.setBody(_bufferBody);
	return _http;
}	


bool	AMethods::errorRequest(Server &server, Request &request){
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

std::string	AMethods::getBufferFile(std::string fileName){
	std::ifstream file(fileName.c_str(), std::ios::in | std::ios::binary);
	std::cout << fileName << "\n";
	if(!file){
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
