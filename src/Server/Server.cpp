/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:38:03 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 12:02:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Request.hpp"
#include <iostream>
#include "AMethods.hpp"
#include "Get.hpp"

using namespace std;

Server::Server() : Socket(), Settings(){}

Server::~Server() {}

void	Server::response(int fd, Request *request) {
	AMethods	*methods;
	HTTP		http;

	methods = defineMethods(request->getMethod());
	methods->selectDirectives(*this, *request);

	if (methods->errorRequest(*request)){
		methods->errorRequest(*request);
		http = methods->getHTTP();
		send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
		return ;
	}
	http  = methods->createHTTP(*this, *request);
	send(fd, http.getHTTP().c_str(), http.getHTTP().length(), 0);
	delete methods;
}

AMethods *Server::defineMethods(std::string method){
	if (method == GET)
		return new Get();
	return new Get();
}

std::string		Server::getMime(std::string path){
	return _mimes.getMime(path);
}