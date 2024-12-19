/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PathLocation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 18:05:15 by rbutzke          ###   ########.fr       */
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
}

std::string PathLocation::getPathLocation(){
	return _pathLocation;
}

