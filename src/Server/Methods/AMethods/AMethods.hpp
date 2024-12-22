/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:51:33 by rbutzke          ###   ########.fr       */
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
#include "FindLocation.hpp"

class AMethods : public FindLocation{
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

	public:
		AMethods();
		virtual ~AMethods();
		std::string 	getFile(std::string url);
		void			selectDirectives(Server &server, Request &request);
		std::string		getBufferFile(std::string fileName);
		bool			errorRequest(Server &server, Request &request);
		virtual HTTP	createHTTP(Server &server, Request &request) = 0;
		HTTP 			getHTTP();
};

