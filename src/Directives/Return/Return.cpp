/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Return.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:42:42 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 16:06:07 by rbutzke          ###   ########.fr       */
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
	if (tokens.empty())
		throw (runtime_error("Error: the return directive cannot be empty."));
	if (tokens.size() == 1){
		if (tokens.begin()->size() < 4 && isNumeric<string>(tokens.front()))
			_returnStatus = toInt(tokens.front());
		else
			_addrReturn = tokens.front();
	}else if (tokens.size() == 2){
		if (not isNumeric(tokens.front()))
			throw (runtime_error("Error: add a valid value to the return directive."));
		_returnStatus = toInt<string>(tokens.front());
		_addrReturn = tokens.back();
	}else
		throw (runtime_error("Error: check the values assigned to the return directive."));
	_instances++;
}

std::string	Return::getReturnAddr(){
	return _addrReturn;
}

int	Return::getReturnStatus(){
	return _returnStatus;
}

Return&Return::operator=(Return const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_addrReturn = origin._addrReturn;
		this->_returnStatus = origin._returnStatus;
	}
	return *this;
}

Return::Return():DirectivesBase(){
	_returnStatus = 308;
	_addrReturn = "";
}