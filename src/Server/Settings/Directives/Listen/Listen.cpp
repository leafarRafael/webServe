/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:58:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:05:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Listen.hpp"
#include "utils.hpp"


using namespace std;

void		Listen::setListen(string listen){
	if (listen.empty())
		return ;
	if (listen.find("listen") == string::npos)
		return ;
	normalize(listen, "listen");
	char limiter = ' ';
	if (listen.find(":") != string::npos)
		limiter = ':';
	list<string> tokens = split<string, char, list<string> >(listen, limiter);
	if (tokens.size() != 2)
		throw (runtime_error("check the arguments of the listen directive"));
	addPortIP(tokens);
	_instances++;
}

void	Listen::addPortIP(std::list<std::string> tokens){
	setIP(tokens.front());
	setPort(tokens.back());
}

string	Listen::getIP(){
	return _ip;
}

string	Listen::getPort(){
	return _port;
}

void	Listen::setPort(std::string port){
	std::ostringstream	oss;
	int					portNumber;

	oss << port;
	std::istringstream	iss(oss.str());
	iss >> portNumber;
	if (portNumber < 1 || portNumber > 65535)
		throw (runtime_error("Port number error"));
	_port = port;
}

void	Listen::setIP(std::string ip){
	if (ip.find("localhost") != string::npos){
		_ip = ip;
		return ;
	}
	list<string> tokens = split<string, char, list<string> >(ip, '.');
	if (tokens.size() != 4)
		throw (runtime_error("IP format error"));
	list<string>::iterator it, ite;
	it = tokens.begin();
	ite = tokens.end();
	while (it != ite){
		if (toInt(*it) < 0 || toInt(*it) > 255)
			throw (runtime_error("IP number error"));
		it++;
	}
	_ip = ip;
}

Listen&Listen::operator=(Listen const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_ip = origin._ip;
		this->_port = origin._port;
	}
	return *this;
}

Listen::Listen():DirectivesBase(), _ip("0.0.0.0"), _port("8080"){}