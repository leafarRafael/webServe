/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTP.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:01:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 14:01:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HTTP.hpp"
#include <sstream>

void	HTTP::setBody(std::string body){
	setHeaders("Content-length", body.length());
	_body.setBody(body);
}

std::string	HTTP::getHTTP() const{
	std::ostringstream http;

	http << _statusLine;
	http << _headers;
	http << _body;
	return http.str();
}

std::ostream &operator<<(std::ostream &os, const HTTP &http){
	os << http.getStatusLine();
	os << http.getHeaders();
	os << http.getHeaders();
	return os;
}

StatusLine		HTTP::getStatusLine() const{
	return _statusLine;
}

Headers			HTTP::getHeaders() const{
	return _headers;
}

Body			HTTP::getBody() const{
	return _body;
}
