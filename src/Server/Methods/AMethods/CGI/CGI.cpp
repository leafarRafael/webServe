/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:19:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/29 19:05:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CGI.hpp"

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstdlib>
#include <utils.hpp>
#include <sstream>

std::string	CGI::commonGatewayInterface(){		
	extern char **__environ;
	pipe(_pipe);
	_pid = fork();
	setEnv();
	if (_pid == -1)
		exit(1);	
	if (_pid == 0){
		writeContentBodyInPipe();
		dup2(_pipe[1], STDOUT_FILENO);
		dup2(_pipe[0], STDIN_FILENO);
		close (_pipe[0]);
		close (_pipe[1]);
		char* const args[] = {(char*)"/usr/bin/python3",(char*)_pathCGI.c_str(),NULL};
		execve(args[0], args, __environ);
	}else{
		waitpid(_pid, &_statusScript, 0);
		unSetEnv();
		close(_pipe[1]);
		_bytesRead = 1;
		while (_bytesRead){
			_bytesRead = read(_pipe[0], _bufferToRead, 4010);
			_bufferToRead[_bytesRead] = '\0';
			_bufferResponsePipe.append(_bufferToRead, _bytesRead);
		}
		close(_pipe[0]);
	}
	return _bufferResponsePipe;
}

void	CGI::writeContentBodyInPipe(){
	write(_pipe[1], _body.c_str(), static_cast<ssize_t>(_body.size()));
}

void CGI::setEnv(){
	setenv((char*)"REQUEST_METHOD", (char*)_requestMethod.c_str(), 1);
	setenv((char*)"CONTENT_LENGTH", (char*)_contentLength.c_str(), 1);
	setenv((char*)"CONTENT_TYPE", (char*)_contentType.c_str(), 1);
	setenv((char*)"QUERY_STRING", (char*)_queryString.c_str(), 1);
	setenv((char*)"PATH_INFO", (char*)_pathInfo.c_str(), 1);
	setenv((char*)"PATH_TRANSLATED", (char*)_pathTraslated.c_str(), 1);
	setenv((char*)"SERVER_NAME", (char*)_server_name.c_str(), 1);
}


void	CGI::setContentLength(std::string contentLength){
	this->_contentLength = contentLength;
}

void	CGI::setContentType(std::string contentType){
	this->_contentType = contentType;
}

void	CGI::setRequestMethod(std::string requestMethod){
	this->_requestMethod = requestMethod;	
}

void	CGI::setQueryString(std::string queryString){
	this->_queryString = queryString;
}

void	CGI::setPathInfo(std::string pathInfo){
	this->_pathInfo = pathInfo;	
}

void	CGI::setBody(std::string body){
	this->_body = body;
}

void	CGI::setHTTPVersion(std::string version){
	this->_version = version;
}

void	CGI::setPathTraslated(std::string pathTraslated){
	this->_pathTraslated = pathTraslated;
}

void	CGI::setServerName(std::string server_name){
	this->_server_name = server_name;
}

void	CGI::setPathCGI(std::string pathCGI){
	this->_pathCGI = pathCGI;
}

void CGI::unSetEnv(){
	unsetenv((char*)"REQUEST_METHOD");
	unsetenv((char*)"CONTENT_LENGTH");
	unsetenv((char*)"CONTENT_TYPE");
	unsetenv((char*)"QUERY_STRING");
	unsetenv((char*)"PATH_INFO");
	unsetenv((char*)"PATH_TRANSLATED");
	unsetenv((char*)"SERVER_NAME");
}	