/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:56:29 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/05 17:56:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Settings.hpp"
#include <iostream>
#include "DataLocation.hpp"
#include "utils.hpp"

using namespace std;

direct_Method	Settings::_ptrMethods[7] = {
	{"listen", &DataServer::setListen},
	{"error_page", &DataServer::setErrorPage},
	{"server_name", &DataServer::setServerName},
	{"client_max_body_size", &DataServer::setMaxBodySize},
	{"root", &DataServer::setRoot},
	{"index", &DataServer::setIndex},
	{"return", &DataServer::setReturn}
};

void	Settings::setDataServer(std::string serverDirectives){
	if (serverDirectives.empty())
		return ;
	list<string> tokens = split<string, char, list<string> >(serverDirectives, '\n');
	addServerDirective(tokens);
}

void	Settings::addServerDirective(list<string> &tokens){
	list<string>::iterator it = tokens.begin(), ite = tokens.end();

	while(it != ite){
		trim(*it);
		if (not it->empty())
			setDirective((*it));
		it++;
	}	
}

void	Settings::setDirective(string directive){
	bool	find = false;
	for(int i = 0; i < 7; i++){
		if(directive.find(_ptrMethods[i].input) != string::npos){
			(_directiveServer.*(_ptrMethods[i].function))(directive);
			find = true;
			break ;
		}
	}
	if (not find){
		std::string error = "Error: directve: " + directive + " unknow.";
		throw (std::runtime_error(error.c_str()));
	}
}

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string	Settings::getIP(){
	return _directiveServer.getIP();
}

std::string	Settings::getPort(){
	return _directiveServer.getPort();
}

std::size_t	Settings::getMaxBodySize(){
	return _directiveServer.getMaxBodySize();	
}

DataLocation	Settings::getDataLocationOBJ(std::string	path){
	return _directiverLocation.getDataLocationOBJ(path);
}

DataServer		Settings::getDataServerOBJ(){
	return _directiveServer;
}


////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Setters////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void 		Settings::setLocation(std::string location){
	_directiverLocation.setLocation(location);
}

void		Settings::setMaxBodySize(std::string maxBodySize){
	_directiveServer.setMaxBodySize(maxBodySize);
}

Settings&Settings::operator=(Settings const &origin){
	if (this != &origin){
		this->_directiveServer = origin._directiveServer;
		this->_directiverLocation = origin._directiverLocation;
	}
	return *this;
}