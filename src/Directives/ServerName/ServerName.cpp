/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerName.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:24:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerName.hpp"
#include "utils.hpp"

using namespace std;

void	ServerName::setServerName(string serverName){
	if (serverName.empty())
		return ;
	if (serverName.find("server_name") == string::npos)
		return ;
	normalize(serverName, "server_name");
	list<string> tokens = split<string, char, list<string> >(serverName, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for server_name directive"));
	_serverName = tokens.front();
	_instances++;
}

std::string	ServerName::getServerName(){
	return _serverName;
}

ServerName&ServerName::operator=(ServerName const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_serverName = origin._serverName;
	}
	return *this;
}

ServerName::ServerName() : DirectivesBase(){}