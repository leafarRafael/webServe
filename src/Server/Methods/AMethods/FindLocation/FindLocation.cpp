/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindLocation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:44:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 18:31:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FindLocation.hpp"
#include "utils.hpp"
#include <list>

DataLocation FindLocation::findLocation(Server &server, Request &request){
	std::string		path;
	DataLocation	location;

	path = request.getPath();
	if (path.length() == 1){
		return location;
	}
	location = server.getDataLocationOBJ(path);
	if (not location.empty()){
		return location;
	}
	return validIfHaveLocation(path, server);
}

DataLocation	FindLocation::validIfHaveLocation(std::string path, Server &server){
	std::string		prefix;
	DataLocation	location;

	prefix = getPrefix(path);
	while (not prefix.empty()){
		location = server.getDataLocationOBJ(prefix);
		if (not location.empty()){
			return location;
		}
		prefix.erase(prefix.size() -1, 1);
		prefix = getPrefix(prefix);
	}
	return location;
}

std::string	FindLocation::getPrefix(std::string path){
	std::string		prefix;
	std::size_t		index = path.length();

	if (prefix.size() == 1 && prefix[0] == '/')
		return prefix;
	prefix = path;
	while(index  !=  0){
		if (prefix[index] == '/')
			return prefix;
		prefix.erase(index, 1);
		index--;
	}
	return prefix;
}
