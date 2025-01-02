/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:38:03 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:51:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Request.hpp"
#include <iostream>
#include "AMethods.hpp"
#include "Get.hpp"
#include "Post.hpp"
#include "Delete.hpp"

using namespace std;

Server::Server() : Socket(), Settings(){}

Server::~Server() {}

void	Server::response(int fd, Request *request) {
	AMethods	*methods;
	HTTP		http;

	methods = defineMethods(request->getMethod());
	methods->setAtributes(*this,  *request);
	if (methods->isReturnDirective()){
		http = methods->getHTTP();
		send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
		return ;
	}
	if (methods->errorRequest(*request)){
		methods->errorRequest(*request);
		http = methods->getHTTP();
		send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
		return ;
	}
	http  = methods->createHTTP();
	send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
	delete methods;
}

AMethods *Server::defineMethods(std::string method){
	if (method == GET)
		return new Get();
	if (method == POST)
		return new Post();
	if (method == DELETE)
		return new Delete();
	return new Get();
}
