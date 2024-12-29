/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:17:03 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/29 19:10:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Server.hpp"
#include "Request.hpp"
#include <map>



class CGI{
	private:
		char				_bufferToRead[4012];
		pid_t				_pid;
		int					_pipe[2];
		int 				_bytesRead;
		int 				_statusScript;
		std::string			_bufferResponsePipe;
		std::string 		_contentLength;
		std::string 		_contentType;
		std::string 		_requestMethod;
		std::string 		_queryString;
		std::string 		_pathInfo;
		std::string 		_pathTraslated;
		std::string 		_pathCGI;
		std::string 		_body;
		std::string			_version;
		std::string			_server_name;

		void	setEnv();
		void 	unSetEnv();
		void	writeContentBodyInPipe();
	public:
		CGI(){};
		~CGI(){};
		std::string	commonGatewayInterface();

		void	setContentLength(std::string contentLength);
		void	setRequestMethod(std::string requestMethod);
		void	setPathTraslated(std::string pathTraslated);
		void	setQueryString(std::string queryString);
		void	setContentType(std::string contentType);
		void	setServerName(std::string server_name);
		void	setHTTPVersion(std::string version);
		void	setPathInfo(std::string pathInfo);
		void	setPathCGI(std::string pathCGI);
		void	setBody(std::string body);
};

