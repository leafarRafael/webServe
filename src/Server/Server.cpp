/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:38:03 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 20:16:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Request.hpp"
#include <iostream>
#include "AMethods.hpp"
#include "Get.hpp"
#include "Post.hpp"
#include "Delete.hpp"
#include "Log.hpp"
#include "utils.hpp"
using namespace std;

Server::Server() : Socket(), Settings(){}

Server::~Server() {}

void	Server::response(int fd, Request *request) {
	AMethods	*methods;
	HTTP		http;

	Log::message("Cliente fd-> ", intToString(fd).c_str(), " # ",
				"Request methodo-> ", request->getMethod().c_str(), " # "
				"Server-> ", getIP().c_str(), ":", getPort().c_str(), " # ",
				"Path-> ", request->getPath().c_str(), 0);
	methods = defineMethods(request->getMethod());
	methods->setAtributes(*this,  *request);
	http  = methods->createHTTP();
	send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
	delete methods;
}

AMethods *Server::defineMethods(std::string method){
	if (method == GET)
		return new Get();
	else if (method == POST)
		return new Post();
	else if (method == DELETE)
		return new Delete();
	return new Get();
}
