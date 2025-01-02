/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:19:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/30 17:19:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CGI.hpp"

# include <sys/wait.h>
# include <signal.h>
# include <cstdlib>
# include <utils.hpp>
# include <sstream>
# include <unistd.h>
# include <ctime>
# include <sys/time.h>

std::string	CGI::commonGatewayInterface(){		
	initPipeAndFork();
	if (_pid == 0)
		childProcess();
	else
		parentProcess();
	return _bufferResponsePipe;
}

void	CGI::initPipeAndFork(){
	if (pipe(_pipe) == -1){
		std::cerr << "Fatal Error: pipe" << "\n";
		exit(666); 
	}
	_startTime = getTime();
	if ((_pid = fork()) == -1){
		std::cerr << "Fatal Error: Fork" << "\n";
		exit(666); 
	}	
}

void	CGI::childProcess(){
	setEnv();
	writeContentBodyInPipe();
	dup2(_pipe[1], STDOUT_FILENO);
	dup2(_pipe[0], STDIN_FILENO);
	close (_pipe[0]);
	close (_pipe[1]);
	extern char **__environ;
	char* const args[] = {(char*)"/usr/bin/python3",(char*)_pathCGI.c_str(), NULL};
	if (execve(args[0], args, __environ) == 1)
		exit(1);
}

void 	CGI::parentProcess(){
	unSetEnv();
	close(_pipe[1]);
	if (timeOut())
		return ;
	_bytesRead = 1;
	while (_bytesRead){
		_bytesRead = read(_pipe[0], _bufferToRead, 4010);
		if (_bytesRead == -1){
			_bufferResponsePipe = "READ_ERROR";
			break ;
		}
		_bufferToRead[_bytesRead] = '\0';
		_bufferResponsePipe.append(_bufferToRead, _bytesRead);
	}
	close(_pipe[0]);
}

bool	CGI::timeOut(){
	int result = 0;

	do{
		result = waitpid(_pid, &_statusScript, WNOHANG);
		if (elapsedTime() > 100000){
			_bufferResponsePipe = "timeOut";
			close(_pipe[0]);
			kill(_pid, SIGKILL);
			return true;
		}
	} while(result == 0);
	if (result == -1){
		close(_pipe[0]);
		return true;
	}
	return false;
}

int	CGI::elapsedTime(){
	return getTime() - _startTime;
}

std::size_t	CGI::getTime(){
	struct timeval	tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000 * 1000 + tv.tv_usec));
}

void	CGI::writeContentBodyInPipe(){
	if (not _body.empty())
		write(_pipe[1], _body.c_str(), static_cast<ssize_t>(_body.size()));
}

void CGI::setEnv(){
	if (not _requestMethod.empty())
		setenv((char*)"REQUEST_METHOD", (char*)_requestMethod.c_str(), 1);
	if (not _contentLength.empty())
		setenv((char*)"CONTENT_LENGTH", (char*)_contentLength.c_str(), 1);
	if (not _contentType.empty())
		setenv((char*)"CONTENT_TYPE", (char*)_contentType.c_str(), 1);
	if (not _queryString.empty())
		setenv((char*)"QUERY_STRING", (char*)_queryString.c_str(), 1);
	if (not _pathInfo.empty())
		setenv((char*)"PATH_INFO", (char*)_pathInfo.c_str(), 1);
	if (not _pathTraslated.empty())
		setenv((char*)"PATH_TRANSLATED", (char*)_pathTraslated.c_str(), 1);
	if (not _server_name.empty())
		setenv((char*)"SERVER_NAME", (char*)_server_name.c_str(), 1);
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

CGI::CGI(){
	_pid = 0;
	_bytesRead = 0;
	_statusScript = 0;
	_bufferResponsePipe = "";
	_contentLength = "";
	_contentType = "";
	_requestMethod = "";
	_queryString = "";
	_pathInfo = "";
	_pathTraslated = "";
	_pathCGI = "";
	_body = "";
	_version = "";
	_server_name = "";
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
