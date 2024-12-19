/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:56:29 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/18 21:22:53 by rbutzke          ###   ########.fr       */
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
			(_server.*(_ptrMethods[i].function))(directive);
			break ;
		}
	}
}


////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string Settings::getErrorPage(int statusCode){
	return _server.getErrorPage(statusCode);
}

std::string	Settings::getIP(){
	return _server.getIP();
}

std::string	Settings::getPort(){
	return _server.getPort();
}

std::string	Settings::getServerName(){
	return _server.getServerName();
}

std::size_t	Settings::getMaxBodySize(){
	return _server.getMaxBodySize();	
}

std::string	Settings::getRoot(){
	return _server.getRoot();
}

std::string	Settings::getIndex(){
	return _server.getIndex();
}

DataLocation	Settings::getLocation(std::string	path){
	return _location.getLocation(path);
}

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Setters////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void 		Settings::setLocation(std::string location){
	_location.setLocation(location);
}

void		Settings::setErrorPage(std::string error_page){
	_server.setErrorPage(error_page);
}

void		Settings::setListen(std::string listen){
	_server.setListen(listen);
}

void		Settings::setServerName(std::string serverName){
	_server.setServerName(serverName);
}

void		Settings::setMaxBodySize(std::string maxBodySize){
	_server.setMaxBodySize(maxBodySize);
}

void		Settings::setRoot(std::string root){
	_server.setRoot(root);
}

void		Settings::setIndex(std::string index){
	_server.setIndex(index);
}