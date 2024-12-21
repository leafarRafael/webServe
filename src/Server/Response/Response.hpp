/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:07:34 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/20 14:10:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <sys/socket.h>
#include <map>
#include "HTTP.hpp"

class Request;

class Response {
	private:
		HTTP								*_response;	
		std::map<std::string, std::string>	_statusLine;
		std::map<std::string, std::string>	_headers;
	
	protected:
		std::string _pathIndex;
		std::string _pathImage;

	public:
		Response();
		~Response();
		void 			setStatus(std::string value, std::string reason);
		void 			setType(std::string type);
		void 			setConnection(std::string connection);
		void 			setLength(std::string length);
		void 			setBody(std::string body);
		void			sendIndex(int fd, std::string indexHTML);
		void			sendImage(int fd, std::string image);
		void			setPathImage(std::string pathImage);
		void			setPathIndex(std::string pathIndex);
		
		std::string		getHttp();
		std::string 	getPathImage() const;
		std::string 	getPathIndex() const;
		virtual void	response(int fd, Request *request) = 0;
};
