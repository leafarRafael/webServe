/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Return.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:42:42 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:20:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Return.hpp"
#include "utils.hpp"

using namespace std;

void		Return::setReturn(std::string addReturn){
	if (addReturn.empty())
		return ;
	if (addReturn.find("return") == string::npos)
		return ;
	normalize(addReturn, "return");
	list<string> tokens = split<string, char, list<string> >(addReturn, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for return directive"));
	_addReturn = tokens.front();
	_instances++;
}

std::string	Return::getReturn(){
	return _addReturn;
}

Return&Return::operator=(Return const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_addReturn = origin._addReturn;
	}
	return *this;
}

Return::Return():DirectivesBase(){}