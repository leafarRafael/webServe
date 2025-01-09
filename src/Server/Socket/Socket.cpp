/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:48:07 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/09 19:58:30 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <cstdlib>

Socket::~Socket(){}

Socket::Socket(){
	std::memset(&_addr, 0, sizeof(_addr));
}

void	Socket::initTCP(const char *port, const char *ip) {
	_socketFd = 0;
	try{
		initSocket();
		setSocketReusable();
		setPortReusable();
		setAddr(port, ip);
		setAddrToSocket();
		putSocketListeningLimit();
	} catch(std::exception &e) {
		std::cerr << e.what();
	}
}

void	Socket::initSocket(){
	_socketFd = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
	if (_socketFd == -1)
		throw std::runtime_error("error: socket()");
}

void	Socket::setSocketReusable(){
	int enable = 1;

	if (setsockopt(_socketFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) == -1)
		throw std::runtime_error("error: setsockopt()");
}

void	Socket::setPortReusable(){
	int enable = 1;

	if (setsockopt(_socketFd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) == -1)
		throw std::runtime_error("error: setsockopt()");
}

void	Socket::setAddr(const char *port, const char *ip) {
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(strtol(port, 0, 10));
	inet_pton(AF_INET, ip, &_addr.sin_addr);
}

void	Socket::setAddrToSocket(){
	if (bind(_socketFd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
		throw std::runtime_error("error: failed to bind socket");
}

void	Socket::putSocketListeningLimit(){
	listen(_socketFd, 10);
}


int		Socket::getSocketFd() const {
	return (this->_socketFd);
}