/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:38:03 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 17:35:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Request.hpp"
#include <iostream>

using namespace std;

Server::Server() : Socket(), Response(), Settings() {}

Server::~Server() {}

void	Server::response(int fd, Request *request) {

	int	error = request->getParserError();
	if (error)
		this->getErrorPage(error);

	if (request->getPath().compare("/") == 0)
		sendIndex(fd, "index/index.html");
	else if (request->getPath().find(".ico") != string::npos || request->getPath().find(".png") != string::npos)
		sendImage(fd, "image/img.png");
}
