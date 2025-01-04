/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:17:03 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 12:35:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Server.hpp"
# include "Request.hpp"
# include <map>

class CGI{
	private:
		std::size_t 		_startTime;
		
		char				_bufferToRead[4012];
		pid_t				_pid;
		int					_pipe[2];
		int 				_bytesRead;
		int 				_statusScript;
		std::string			_bufferResponsePipe;
		std::size_t			_maxBodySize;

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

		void				setEnv();
		void				unSetEnv();
		bool				writeContentBodyInPipe();
		bool				initPipeAndFork();
		void				childProcess();
		void				parentProcess();
		bool				timeOut();
		int					elapsedTime();
		std::size_t			getTime();
		void				addPathInterpreterExecutable(char** args);
		bool				waitValidExitStatus();

	public:
		CGI();
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
		void	setMaxBodySize(std::size_t maxBody);
};

