/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseValidation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:41:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 12:23:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseValidation.hpp"
#include <stdexcept>
#include <cstring>
#include <cerrno> 
#include <sstream>
#include <iostream>
#include "utils.hpp"



void		ParseValidation::validFileExtension(std::string file){
	if (file.substr(file.length() -5, file.length()).find(".conf") == std::string::npos)
		throw (std::runtime_error("Invalid format file conf."));
}

void		ParseValidation::validCurlyBraces(std::string &buffer){
	std::size_t	index = 0, openBraces = 0, closeBraces = 0;
	
	while (index < buffer.length()){
		if (buffer[index] == '{')
			openBraces++;
		if (buffer[index] == '}')
			closeBraces++;
		if (closeBraces > openBraces)
			throw (std::runtime_error("Check the curly braces {}."));
		index++;
	}
	if (closeBraces != openBraces)
		throw (std::runtime_error("Check the curly braces {}."));
}

void	ParseValidation::validDirectivesServer(std::string &buffer){
	int	server = 0, listen = 0, server_name = 0, root = 0;
	std::istringstream	ss(buffer);
	std::string			line;

	while(std::getline(ss, line, '\n')){
		if (validWord(line, "server", '{'))
			server++;
		if (validWord(line, "listen", '{'))
			listen++;
		if (validWord(line, "server_name", '{'))
			server_name++;
		if (validWord(line, "root", '{'))
			root++;
	}
	if (server == 0)
		throw (std::runtime_error("Directive 'server' in scope Server not found."));
	if (listen == 0)
		throw (std::runtime_error("Directive 'listen' in scope Server not found."));
	if (server_name == 0)
		throw (std::runtime_error("Directive 'server_name' in scope Server not found."));
	if (root == 0)
		throw (std::runtime_error("Directive 'root' in scope Server not found."));
}

void	ParseValidation::validDirectivesLocation(std::string &buffer){
	std::istringstream	ss(buffer);
	std::string			line;
	int					root = 0;

	while(std::getline(ss, line, '\n')){
		if (validWord(line, "root", '{'))
			root++;
	}
	if (root == 0)
		throw (std::runtime_error("Directive root in scope location not found."));
}

/* bool validWord(std::string buffer, std::string toFind, char c){
	std::size_t	pos;
	char		prefix, sufix;

	pos = buffer.find(toFind);
	if (pos == std::string::npos)
		return false;
	sufix = buffer[toFind.length() + pos];
	if (pos != 0){
		prefix = buffer[pos-1];
		if (!isspace(prefix) || (!isspace(sufix) && sufix != c))
			return false;
	}
	if (pos == 0){
		if (!isspace(sufix) && sufix != c)
			return false;
	}
	return true;
} */