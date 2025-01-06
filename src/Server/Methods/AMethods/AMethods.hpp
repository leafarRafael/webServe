/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/06 12:57:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>
#include <map>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include "HTTP.hpp"
#include "Request.hpp"
#include "Server.hpp"
#include "CGI.hpp"
#include "DataRequest.hpp"
#include "DataDirectives.hpp"
#include "Mime.hpp"


enum type{
	T_NOT_EXIST = -1,
	T_DIRECTORY = 1,
	T_FILE = 2,
};

class AMethods : public DataRequest, public DataDirectives{
	protected:
		Mime			_mimes;
		CGI				_cgi;
		HTTP			_http;
		std::string		_pathTraslated;
		std::string		_pathCGITraslated;

		int				_statusCode;
		std::string		_reasonPhrase;
		std::string		_contentType;
		std::string		_bufferBody;

		void			setPathTraslated(Server &server);
		void			addResponseBody(std::string fileName);
		void			setCGI(Server &server);
		std::string		getMime(std::string path);
		int				getErrorValue();
		int				pathIs(const std::string& path);
		
		std::string 	getFile(std::string url);
		void			processFile();
		void			processReturnDirective();
		std::string		commonGatewayInterface();
	public:
		void			processError(int statusError);
		AMethods();
		virtual ~AMethods();
		HTTP 			getHTTP();
		void			setAtributes(Server &server, Request &request);
		virtual HTTP	createHTTP() = 0;
};

