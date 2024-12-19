/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllowMethods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 15:20:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AllowMethods.hpp"
#include "utils.hpp"
#include <algorithm>

using namespace std;

void	AllowMethods::setAllowMethods(std::string allowMethods){
	if (allowMethods.empty())
		return ;
	if (allowMethods.find("allow_methods") == string::npos)
		return ;
	normalize(allowMethods, "allow_methods");
	list<string> tokens = split<string, char, list<string> >(allowMethods, ' ');
	_allowMethods = tokens;
}

std::list<std::string>	AllowMethods::getAllowMethods(){
	return _allowMethods;
}

bool AllowMethods::isAllowedMethod(std::string method){
	if (find(_allowMethods.begin(), _allowMethods.end(), method) != _allowMethods.end())
		return true;
	return false;
}