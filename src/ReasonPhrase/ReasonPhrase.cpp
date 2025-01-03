/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReasonPhrase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:34:33 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 15:24:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReasonPhrase.hpp"

std::map<int, std::string>	ReasonPhrase::_reasonPhrase;
ReasonPhrase::ReasonPhrase(){}
ReasonPhrase::~ReasonPhrase(){}

std::string	ReasonPhrase::getPhrase(int status){
	if (_reasonPhrase.empty())
		initReasonPhrase();
	if (not _reasonPhrase.count(status))
		return std::string("not found");
	return _reasonPhrase[status];
}

void	ReasonPhrase::initReasonPhrase(){
    _reasonPhrase[100] = "Continue";
    _reasonPhrase[101] = "Switching Protocols";
    _reasonPhrase[200] = "OK";
    _reasonPhrase[201] = "Created";
    _reasonPhrase[202] = "Accepted";
    _reasonPhrase[203] = "Non-Authoritative Information";
    _reasonPhrase[204] = "No Content";
    _reasonPhrase[205] = "Reset Content";
    _reasonPhrase[206] = "Partial Content";
    _reasonPhrase[300] = "Multiple Choices";
    _reasonPhrase[301] = "Moved Permanently";
    _reasonPhrase[302] = "Found";
    _reasonPhrase[303] = "See Other";
    _reasonPhrase[304] = "Not Modified";
    _reasonPhrase[305] = "Use Proxy";
    _reasonPhrase[307] = "Temporary Redirect";
    _reasonPhrase[400] = "Bad Request";
    _reasonPhrase[401] = "Unauthorized";
    _reasonPhrase[402] = "Payment Required";
    _reasonPhrase[403] = "Forbidden";
    _reasonPhrase[404] = "Not Found";
    _reasonPhrase[405] = "Method Not Allowed";
    _reasonPhrase[406] = "Not Acceptable";
    _reasonPhrase[407] = "Proxy Authentication Required";
    _reasonPhrase[408] = "Request Timeout";
    _reasonPhrase[409] = "Conflict";
    _reasonPhrase[410] = "Gone";
    _reasonPhrase[411] = "Length Required";
    _reasonPhrase[412] = "Precondition Failed";
    _reasonPhrase[413] = "Payload Too Large";
    _reasonPhrase[414] = "URI Too Long";
    _reasonPhrase[415] = "Unsupported Media Type";
    _reasonPhrase[416] = "Range Not Satisfiable ";
    _reasonPhrase[417] = "Expectation Failed";
    _reasonPhrase[426] = "Upgrade Required";
    _reasonPhrase[500] = "Internal Server Error";
    _reasonPhrase[501] = "Not Implemented";
    _reasonPhrase[502] = "Bad Gateway";
    _reasonPhrase[503] = "Service Unavailable";
    _reasonPhrase[504] = "Gateway Timeout";
    _reasonPhrase[505] = "HTTP Version Not Supported";
}
