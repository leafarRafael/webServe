/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:56:29 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:51:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Settings.hpp"
#include <iostream>
#include "DataLocation.hpp"
#include "utils.hpp"

using namespace std;

direct_Method	Settings::_ptrMethods[6] = {
	{"listen", &DataServer::setListen},
	{"error_page", &DataServer::setErrorPage},
	{"server_name", &DataServer::setServerName},
	{"client_max_body_size", &DataServer::setMaxBodySize},
	{"root", &DataServer::setRoot},
	{"index", &DataServer::setIndex},
};

void	Settings::setServerDirective(std::string serverDirectives){
	if (serverDirectives.empty())
		return ;
	list<string> tokens = split<string, char, list<string> >(serverDirectives, '\n');
	addServerDirective(tokens);
}

void	Settings::addServerDirective(list<string> &tokens){
	list<string>::iterator it = tokens.begin(), ite = tokens.end();

	while(it != ite){
		setDirective((*it));
		it++;
	}	
}

void	Settings::setDirective(string directive){
	for(int i = 0; i < 6; i++){
		if(directive.find(_ptrMethods[i].input) != string::npos){
			(_directiveServer.*(_ptrMethods[i].function))(directive);
			break ;
		}
	}
}


////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string Settings::getErrorPage(int statusCode){
	return _directiveServer.getErrorPage(statusCode);
}

std::string	Settings::getIP(){
	return _directiveServer.getIP();
}

std::string	Settings::getPort(){
	return _directiveServer.getPort();
}

std::string	Settings::getServerName(){
	return _directiveServer.getServerName();
}

std::size_t	Settings::getMaxBodySize(){
	return _directiveServer.getMaxBodySize();	
}

std::string	Settings::getRoot(){
	return _directiveServer.getRoot();
}

std::string	Settings::getIndex(){
	return _directiveServer.getIndex();
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

void		Settings::setErrorPage(std::string error_page){
	_directiveServer.setErrorPage(error_page);
}

void		Settings::setListen(std::string listen){
	_directiveServer.setListen(listen);
}

void		Settings::setServerName(std::string serverName){
	_directiveServer.setServerName(serverName);
}

void		Settings::setMaxBodySize(std::string maxBodySize){
	_directiveServer.setMaxBodySize(maxBodySize);
}

void		Settings::setRoot(std::string root){
	_directiveServer.setRoot(root);
}

void		Settings::setIndex(std::string index){
	_directiveServer.setIndex(index);
}

Settings&Settings::operator=(Settings const &origin){
	if (this != &origin){
		this->_directiveServer = origin._directiveServer;
		this->_directiverLocation = origin._directiverLocation;
	}
	return *this;
}