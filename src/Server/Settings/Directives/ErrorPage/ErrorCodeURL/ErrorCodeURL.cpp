/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorCodeURL.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:22:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:01:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorCodeURL.hpp"
#include <sstream>
#include <iostream>
#include "utils.hpp"

void	ErrorCodeURL::setURLErrorPage(std::string error_page){
	if (_urlErrorPage.empty()){
		_urlErrorPage = error_page;
		_instances++;
	}
}

void	ErrorCodeURL::setURLErrorCode(int errorCode){
	if (std::find(_erroCode.begin(), _erroCode.end(), errorCode) == _erroCode.end()){
		_erroCode.push_back(errorCode);
		_instances++;
	}
}

std::string	ErrorCodeURL::getUrlErrorPage(int errorCode){
	if (std::find(_erroCode.begin(), _erroCode.end(), errorCode) != _erroCode.end()){
		return _urlErrorPage;	
	}
	return std::string();
}

void	ErrorCodeURL::setURLErrorCode(std::string errorCode){
	int	errorCodeInt = toInt(errorCode);

	if (std::find(_erroCode.begin(), _erroCode.end(), errorCodeInt) == _erroCode.end()){
		_erroCode.push_back(errorCodeInt);
		_instances++;
	}
}

ErrorCodeURL&ErrorCodeURL::operator=(ErrorCodeURL const & origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_erroCode = origin._erroCode;
		this->_urlErrorPage = origin._urlErrorPage;
	}
	return *this;
}

ErrorCodeURL::ErrorCodeURL(): DirectivesBase(){}