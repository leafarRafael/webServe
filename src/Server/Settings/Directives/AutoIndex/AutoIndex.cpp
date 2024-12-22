/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndex.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:21:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 09:58:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AutoIndex.hpp"
#include "utils.hpp"
#include <list>

using namespace std;

void		AutoIndex::setAutoIndex(std::string autoIndex){
	if (autoIndex.empty())
		return ;
	if (autoIndex.find("autoindex") == string::npos)
		return ;
	normalize(autoIndex, "autoindex");
	list<string> tokens = split<string, char, list<string> >(autoIndex, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for autoindex directive"));
	_autoIndex = tokens.front();
	_instances++;
}

std::string	AutoIndex::getAutoIndex(){
	if (_autoIndex.empty())
		return "";
	return _autoIndex;
}

bool		AutoIndex::getAutoIndexBool(){
	if (_autoIndex.empty())
		return false;
	if (_autoIndex.find("on") != string::npos)
		return true;
	return false;	
}

AutoIndex&AutoIndex::operator=(AutoIndex const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_autoIndex = origin._autoIndex;
	}
	return *this;
}

AutoIndex::AutoIndex(): DirectivesBase(){}