/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/29 13:11:25 by rbutzke          ###   ########.fr       */
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


class AMethods : public DataRequest, public DataDirectives{
	protected:
		CGI				_cgi;
		HTTP			_http;
		std::string		_pathTraslated;
		std::string		_pathCGITraslated;

		int				_statusCode;
		std::string		_statusMensagen;
		std::string		_contentType;
		std::string		_bufferBody;
		std::string		getBufferFile(std::string fileName);

	public:
		AMethods();
		virtual ~AMethods();
		HTTP 			getHTTP();
		bool			errorRequest(Request &request);
		std::string 	getFile(std::string url);

		std::string		commonGatewayInterface(Server &server);
		virtual HTTP	createHTTP(Server &server, Request &request) = 0;
};
