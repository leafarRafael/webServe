/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:17:03 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/25 11:37:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Server.hpp"
#include "Request.hpp"
#include <map>

#define SCRIPTNAME "SCRIPT_FILENAME"
#define QUERY_STRING "SCRIPT_FILENAME"
#define REQUEST_METHOD "SCRIPT_FILENAME"
#define CONTENT_LENGTH "SCRIPT_FILENAME"

class CGI{
	private:

		std::map<std::string, std::string> _environment;


	public:
		CGI(){};
		~CGI(){};

		std::string	commonGatewayInterface(Server &server, Request &request);
};

