/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseConf.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:35:36 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/09 18:57:30 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseConf.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno> 
#include <sstream>
#include "utils.hpp"
#include "Log.hpp"

std::list<Server>	ParseConf::parseFileConf(std::string file){
	try{
		validFileExtension(file);
		readFile(file);
		validCurlyBraces(_buffer);
		addBlockServer(_buffer);
		validDirectives();
		initServers();
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		throw (std::runtime_error(""));
	}
	return _server;
}

void	ParseConf::readFile(std::string fileConf){
	std::ifstream file(fileConf.c_str(), std::ios::in | std::ios::binary);
	if(!file)
		throw (std::runtime_error(std::strerror(errno)));
	std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	removeComments(buffer);
	_buffer = buffer;
	file.close();
}

void		ParseConf::removeComments(std::string &buffer){
	std::istringstream	ss(buffer);
	std::string			line;
	std::string			fileBuffer;
	std::size_t			pos;

	while(std::getline(ss, line, '\n')){
		pos = line.find('#');
		if (pos != std::string::npos)
			line.erase(pos, line.length());
		if (not line.empty()){
			line += '\n';
			fileBuffer += line;
		}
	}
	buffer = fileBuffer;
}

void	ParseConf::validDirectives(){
	std::list<blockServer>::iterator it;
	std::list<std::string>::iterator locait;

	for (it = _serverBlock.begin(); it != _serverBlock.end(); it++){
		validDirectivesServer(it->_serverScope);
		for(locait = it->_locationsScope.begin(); locait != it->_locationsScope.end(); locait++){
			validDirectivesLocation(*locait);
		}
	}
}

void	ParseConf::initServers(){
	std::list<blockServer>::iterator	it;
	std::list<std::string>::iterator	locait;
	std::map<std::string, std::string>	ctlrPort;

	for (it = _serverBlock.begin(); it != _serverBlock.end(); it++){
		Server	server;
		setServerScope(it->_serverScope, server);
		for(locait = it->_locationsScope.begin(); locait != it->_locationsScope.end(); locait++){
			server.setLocation(*locait);
		}
		if (not ctlrPort.count(server.getPort())){
			ctlrPort[server.getPort()];
			server.initTCP(server.getPort().c_str(), server.getIP().c_str());
			Log::message("Socket created:", "IP", server.getIP().c_str(),
				"Port:", server.getPort().c_str(), 0);
			_server.push_back(server);
		}
	}
}

void	ParseConf::setServerScope(std::string &serverDirectives, Server &server){
	removeToString(serverDirectives, "server");
	removeToString(serverDirectives, "{");
	removeToString(serverDirectives, "}");
	trim(serverDirectives);
	server.setDataServer(serverDirectives);
}
