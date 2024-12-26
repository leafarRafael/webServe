/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/23 17:06:19 by rbutzke          ###   ########.fr       */
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

class AMethods {
	protected:
		HTTP			_http;
		Root			_root;
		Index			_index;
		ErrorPage		_errorPage;
		MaxBodySize		_maxBodySize;
		AutoIndex		_autoIndex;
		AllowMethods	_allowMethods;
		Return			_returnIndex;

		int				_statusCode;
		std::string		_statusMensagen;
		std::string		_contentType;
		std::string		_bufferBody;

		std::string 	getFile(std::string url);
		void			addLocationDirectives(DataLocation dataLocation);
		void			addGlobalDirectives(DataServer dataServer);
		
		std::string		getBufferFile(std::string fileName);

	public:
		AMethods();
		virtual ~AMethods();

		HTTP 			getHTTP();
		DataLocation	findDataLocation(Server &server, Request &request);
		bool			errorRequest(Request &request);
		void			selectDirectives(Server &server, Request &request);
		virtual HTTP	createHTTP(Server &server, Request &request) = 0;
};
