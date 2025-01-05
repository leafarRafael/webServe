/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:19:22 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 21:44:59 by rbutzke          ###   ########.fr       */
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
# include "Log.hpp"
# include <cstring>
# include <cerrno>
#include <fstream>
#include "SignalHandler.hpp"

std::string	CGI::commonGatewayInterface(){
	if(initPipeAndFork())
		return _bufferResponsePipe;
	if (_pid == 0)
		childProcess();
	else
		parentProcess();
	return _bufferResponsePipe;
}

bool	CGI::initPipeAndFork(){
	if (pipe(_pipe) == -1){
		Log::message("Pipe error ", strerror(errno), 0);
		_bufferResponsePipe = "STATUS CODE: 500";
		return true;
	}
	_startTime = getTime();
	if ((_pid = fork()) == -1){
		Log::message("Fork error ", strerror(errno), 0);
		_bufferResponsePipe = "STATUS CODE: 500";
		close(_pipe[0]);
		close(_pipe[1]);
		return true;
	}
	return false;
}

void	CGI::childProcess(){
	setEnv();
	dup2(_pipe[1], STDOUT_FILENO);
	dup2(_pipe[0], STDIN_FILENO);
	close(_pipe[0]);
	close(_pipe[1]);
	extern char **__environ;
	char* args[3];
	addPathInterpreterExecutable(args);
	execve(args[0], args, __environ);
	SignalHandler::setBreakLooping(true);
	Log::message("Execve error ", strerror(errno), 0);
}

void CGI::addPathInterpreterExecutable(char** args){
	if (_pathCGI.find(".py") != std::string::npos){
		args[0] = (char*)"/usr/bin/python3";
		args[1] = (char*)_pathCGI.c_str();
		args[2] = NULL;
	}
	else if (_pathCGI.find(".php") != std::string::npos){
		args[0] = (char*)"/usr/bin/php";
		args[1] = (char*)_pathCGI.c_str();
		args[2] = NULL;
	}
	else{
		args[0] = (char*)"/usr/bin/bash";
		args[1] = (char*)_pathCGI.c_str();
		args[2] = NULL;
	}
}

void 	CGI::parentProcess(){
	if (writeContentBodyInPipe())
		return ;
	unSetEnv();
	close(_pipe[1]);
	if (waitValidExitStatus())
		return ;
	_bytesRead = 1;
	while (_bytesRead){
		_bytesRead = read(_pipe[0], _bufferToRead, 4010);
		if (_bytesRead == -1){
			_bufferResponsePipe = "STATUS CODE: 504";
			Log::message("read error; broken pipe ", 0);
			break ;
		}
		_bufferToRead[_bytesRead] = '\0';
		_bufferResponsePipe.append(_bufferToRead, _bytesRead);
	}
	if (_bufferResponsePipe.empty())
		_bufferResponsePipe = "STATUS CODE: 204";
	close(_pipe[0]);
}

bool	CGI::writeContentBodyInPipe(){
	if (_maxBodySize < _body.length()){
		_bufferResponsePipe = "STATUS CODE: 500";
		close(_pipe[0]);
		close(_pipe[1]);
		kill(_pid, SIGKILL);
		unSetEnv();
		return true;
	}
	if (_body.empty())
		return false;
	const char	*body = _body.c_str();
	ssize_t		bodySize = static_cast<ssize_t>(_body.size());
	ssize_t		buffer = 4098;
	ssize_t		positionInBuffer = 0;
	ssize_t		bufferToWritten = 0;
	while(bodySize > 0){
		if (buffer <= bodySize)
			bufferToWritten = buffer;
		else
			bufferToWritten = bodySize;
		write(_pipe[1], &body[positionInBuffer], bufferToWritten);
		positionInBuffer += bufferToWritten;
		bodySize -= bufferToWritten;	
	}
	return false;
}

bool	CGI::waitValidExitStatus(){
	if (timeOut())
		return true;
	if (WIFEXITED(_statusScript) && WEXITSTATUS(_statusScript)){
		_bufferResponsePipe = "STATUS CODE: 500";
		close(_pipe[0]);
		return true;
	}
	return false;
}

bool	CGI::timeOut(){
	int result = 0;

	do{
		result = waitpid(_pid, &_statusScript, WNOHANG);
		if (elapsedTime() > 10000000){
			_bufferResponsePipe = "STATUS CODE: 504";
			close(_pipe[0]);
			kill(_pid, SIGKILL);
			return true;
		}
	} while(result == 0);
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
	_maxBodySize = 0;
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

void	CGI::setMaxBodySize(std::size_t maxBody){
	_maxBodySize = maxBody;
}

void	CGI::setPathCGI(std::string pathCGI){
	this->_pathCGI = pathCGI;
}
