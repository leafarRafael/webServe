/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PathLocation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:19:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PathLocation.hpp"
#include "utils.hpp"

using namespace std;

void	PathLocation::setPathLocation(string pathLocation){
	if (pathLocation.empty())
		return ;
	if (pathLocation.find("location") == string::npos)
		return ;
	normalize(pathLocation, "location");
	list<string> tokens = split<string, char, list<string> >(pathLocation, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for pathLocation directive"));
	_pathLocation = tokens.front();
	_instances++;
}

std::string PathLocation::getPathLocation(){
	return _pathLocation;
}

PathLocation&PathLocation::operator=(PathLocation const &origin){
	if(this != &origin)
	{
		DirectivesBase::operator=(origin);
		this->_pathLocation = origin._pathLocation;
	}
	return *this;
}

PathLocation::PathLocation() : DirectivesBase(), _pathLocation(""){}