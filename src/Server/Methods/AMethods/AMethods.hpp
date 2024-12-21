/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMethods.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:28:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 10:31:14 by rbutzke          ###   ########.fr       */
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
		HTTP		_http;
		std::string	_method;

		int			_statusCode;
		std::string	_statusMensagen;
		std::string	_contentType;
		std::string	_bufferBody;

	public:
		AMethods();
		virtual ~AMethods();
		std::string		getBufferFile(std::string fileName);
		bool			errorRequest(Server &server, Request &request);
		virtual HTTP	createHTTP(Server &server, Request &request) = 0;
		void			name();
		HTTP 			getHTTP();
};

