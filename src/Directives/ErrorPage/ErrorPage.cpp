/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorPage.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:31:14 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 18:58:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorPage.hpp"
#include "utils.hpp"
#include "ErrorCodeURL.hpp"
#include <ostream>
#include <list>
#include <cctype>

using namespace std;

void		ErrorPage::setErrorPage(string &error_page){
	ErrorCodeURL	errorContent;

	if (error_page.empty())
		return ;
	if (error_page.find("error_page") == std::string::npos)
		return ;
	normalize(error_page, "error_page");
	list<string> tokens = split<string, char, list<string> >(error_page, ' ');
	findSetErrorCode(tokens, errorContent);
	findSetErrorPage(tokens, errorContent);
	_error.push_back(errorContent);
	_instances++;
}

void	ErrorPage::findSetErrorCode(list<string> &tokens, ErrorCodeURL &errorContent){	
	list<string>::iterator it, ite;

	it = tokens.begin();
	ite = tokens.end();
	while (it != ite){
		trim(*it);
		if (isNumeric(*it)){
			errorContent.setURLErrorCode(*it);
			it = tokens.erase(it);
		}
		else
			it++;
	}
}

void	ErrorPage::findSetErrorPage(list<string> &tokens, ErrorCodeURL &errorContent){	
	if (tokens.empty() || tokens.size() != 1)
		throw (runtime_error("ErrorPage not found"));
	errorContent.setURLErrorPage(*tokens.begin());
}

string	ErrorPage::getErrorPage(int errorCode){
	std::list<ErrorCodeURL>::iterator	it, ite;
	std::string							errorPage;
	it = _error.begin();
	ite = _error.end();
	while (it != ite){
		errorPage = it->getUrlErrorPage(errorCode);
 		if (!errorPage.empty()){
			return errorPage;
		}
		++it;
	}
	return std::string();
}


ErrorPage&ErrorPage::operator=(ErrorPage const &origin){
	if (this != &origin){
		this->_error = origin._error;
	}
	return *this;
}

bool		ErrorPage::empty(){
	if(_instances)
		return false;
	return true;
}