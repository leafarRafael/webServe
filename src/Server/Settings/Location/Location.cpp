/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:30:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 18:31:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"
#include "utils.hpp"
#include <algorithm>

using namespace std;

Location::Location(){}
Location::~Location(){}

t_pointer Location::direc[8] = {
	{"allow_methods",  &DataLocation::setAllowMethods},
	{"autoindex", &DataLocation::setAutoIndex},
	{"error_page", &DataLocation::setErrorPage},
	{"index", &DataLocation::setIndex},
	{"client_max_body_size", &DataLocation::setMaxBodySize},
	{"return", &DataLocation::setReturn},
	{"root", &DataLocation::setRoot},
	{"location", &DataLocation::setPathLocation},	
};

void	Location::setLocation(std::string location){
	DataLocation	data;
	if (location.empty())
		return ;
	list<string> tokens = split<string, char, list<string> >(location, '\n');
	normalizeLocation(tokens);
	addLocationToData(tokens, data);
	_locations.push_back(data);
}

void	Location::addLocationToData(list<string> &tokens, DataLocation &data){
	list<string>::iterator it = tokens.begin(), ite = tokens.end();

	while(it != ite){
		setDirective((*it), data);
		it++;
	}	
}

void	Location::normalizeLocation(list<string> &tokens){
	list<string>::iterator it = tokens.begin(), ite = tokens.end();

	while(it != ite){
		normalize(*it, "{");
		normalize(*it, "}");
		it++;
	}
}

void	Location::setDirective(string directive, DataLocation &data){
	for(int i = 0; i < 8; i++){
		if(directive.find(direc[i].input) != string::npos){
			(data.*(direc[i].function))(directive);
			break ;
		}
	}
}

DataLocation	Location::getDataLocationOBJ(std::string path){
	std::list<DataLocation>::iterator it = _locations.begin(), ite = _locations.end();

	while(it != ite){
		if (validWord(it->getPathLocation(), path, '\0')){
			return *it;
		}
		it++;
	}
	return DataLocation();
}

Location&Location::operator=(Location const &origin){
	if (this != &origin){
		this->_locations = origin._locations;
	}
	return *this;
}