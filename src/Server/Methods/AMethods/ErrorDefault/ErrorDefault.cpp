/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDefault.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:19:45 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 09:11:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ErrorDefault.hpp"
#include "utils.hpp"

std::map<int, std::string> ErrorDefault::_error;

std::string ErrorDefault::getErrorDefault(int errorCode){
    if (_error.empty())
	    initError();
    std::string errorvalue = intToString(errorCode);
    std::string errorMensage = "Unknown Error";
    if (_error.count(errorCode))
        errorMensage = _error[errorCode];
    std::string html = "<html>\n"
                       "<head><title>" + errorvalue + " " + errorMensage + "</title></head>\n"
                       "<body>\n"
                       "<center><h1>" + errorvalue + " " + errorMensage + "</h1></center>\n"
                       "<hr><center>myWevServ/" "MyWebServ" "</center>\n"
                       "</body>\n"
                       "</html>\n";

    return html;
}

void ErrorDefault::initError() {
    _error[400] = "Bad Request";
    _error[401] = "Unauthorized";
    _error[402] = "Payment Required";
    _error[403] = "Forbidden";
    _error[404] = "Not Found";
    _error[405] = "Method Not Allowed";
    _error[406] = "Not Acceptable";
    _error[407] = "Proxy Authentication Required";
    _error[408] = "Request Timeout";
    _error[409] = "Conflict";
    _error[410] = "Gone";
    _error[411] = "Length Required";
    _error[412] = "Precondition Failed";
    _error[413] = "Payload Too Large";
    _error[414] = "URI Too Long";
    _error[415] = "Unsupported Media Type";
    _error[416] = "Range Not Satisfiable";
    _error[417] = "Expectation Failed";
    _error[418] = "I'm a teapot";
    _error[422] = "Unprocessable Entity";
    _error[423] = "Locked";
    _error[424] = "Failed Dependency";
    _error[425] = "Too Early";
    _error[426] = "Upgrade Required";
    _error[429] = "Too Many Requests";
    _error[444] = "No Response";
    _error[449] = "Retry With";
    _error[450] = "Blocked by Windows Parental Controls";
    _error[451] = "Unavailable For Legal Reasons";
    _error[499] = "Client Closed Request";
    _error[500] = "Internal Server Error";
    _error[501] = "Not Implemented";
    _error[502] = "Bad Gateway";
    _error[503] = "Service Unavailable";
    _error[504] = "Gateway Timeout";
    _error[505] = "HTTP Version Not Supported";
}
