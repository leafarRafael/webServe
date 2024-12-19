/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorCodeURL.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:22:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/16 18:41:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorCodeURL.hpp"
#include <sstream>
#include <iostream>
#include "utils.hpp"

void	ErrorCodeURL::setURLErrorPage(std::string error_page){
	if (_urlErrorPage.empty())
		_urlErrorPage = error_page;
}

void	ErrorCodeURL::setURLErrorCode(int errorCode){
	if (std::find(_erroCode.begin(), _erroCode.end(), errorCode) == _erroCode.end())
		_erroCode.push_back(errorCode);
}

std::string	ErrorCodeURL::getUrlErrorPage(int errorCode){
	if (std::find(_erroCode.begin(), _erroCode.end(), errorCode) != _erroCode.end()){
		return _urlErrorPage;	
	}
	return std::string();
}

void	ErrorCodeURL::setURLErrorCode(std::string errorCode){
	int	errorCodeInt = toInt(errorCode);

	if (std::find(_erroCode.begin(), _erroCode.end(), errorCodeInt) == _erroCode.end())
		_erroCode.push_back(errorCodeInt);
}