/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseTokens.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:02:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/18 17:51:46 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseTokens.hpp"
#include <sstream>
#include <iostream>
#include "utils.hpp"

void	ParseTokens::addBlockServer(std::string &buffer){
	blockServer		server;
	std::size_t		index = buffer.find('{');
	std::string		tokenServer;

	if (index == std::string::npos)
		return ;
	index++;
	int open = 1;
	while (index < buffer.length()){
		if (buffer[index] == '{')
			open++;
		if (buffer[index] == '}')
			open--;
		index++;
		if (open == 0)
			break ;
	}
	server._serverScope = buffer.substr(0, index);
	buffer.erase(0, index);
	addBlockLocation(server);
	_serverBlock.push_back(server);
	addBlockServer(buffer);
}

void	ParseTokens::addBlockLocation(blockServer &server){
	std::size_t	pos = 0, braces = 0;
	std::string	location;
	
	pos = server._serverScope.find("location");
	braces = server._serverScope.find('}');
	if (pos == std::string::npos || braces == std::string::npos) 
		return ;
	location = server._serverScope.substr(pos, braces - pos +1);
	server._serverScope.erase(pos, braces - pos +1);
	server._locationsScope.push_back(location);
	addBlockLocation(server);
}
