/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:50:13 by rbutzke          ###   ########.fr       */
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
# include "Mime.hpp"


class AMethods : public DataRequest, public DataDirectives{
	protected:
		Mime			_mimes;
		CGI				_cgi;
		HTTP			_http;
		std::string		_pathTraslated;
		std::string		_pathCGITraslated;

		int				_statusCode;
		std::string		_statusMensagen;
		std::string		_contentType;
		std::string		_bufferBody;
		void			setPathTraslated(Server &server);
		std::string		getBufferFile(std::string fileName);
		void			setCGI(Server &server);
		std::string		getMime(std::string path);
		void			processError(int statusError);

	public:
		AMethods();
		virtual ~AMethods();
		HTTP 			getHTTP();
		bool			errorRequest(Request &request);
		bool			isReturnDirective();
		std::string 	getFile(std::string url);
		std::string		commonGatewayInterface();
		void			setAtributes(Server &server, Request &request);
		virtual HTTP	createHTTP() = 0;
};

