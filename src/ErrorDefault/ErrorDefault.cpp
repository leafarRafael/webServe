/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDefault.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:26:45 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 17:56:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorDefault.hpp"
#include <sstream>
#include <iostream>

std::map<int, std::string> ErrorDefault::_error;

std::string	ErrorDefault::getHTML(int errorCode){
	std::ostringstream	html;

    if (_error.empty())
        initError();
    html << HTML_ERROR_OPEN << "\n";
    html << _error[errorCode] << "\n";
    html << HTML_ERROR_CLOSE << "\n";
    return html.str();
}

void	ErrorDefault::initError(){
	_error[100] = "<h1>100 Continue</h1>\n<p>The server has received the request headers, and the client should proceed to send the request body.</p>";
    _error[101] = "<h1>101 Switching Protocols</h1>\n<p>The server is switching protocols as requested by the client.</p>";
    _error[200] = "<h1>200 OK</h1>\n<p>The request was successful.</p>";
    _error[204] = "<h1>204 No Content</h1>\n<p>The server successfully processed the request but is not returning any content.</p>";
    _error[301] = "<h1>301 Moved Permanently</h1>\n<p>The requested resource has been permanently moved to a new location.</p>";
    _error[302] = "<h1>302 Found</h1>\n<p>The requested resource resides temporarily at a different URI.</p>";
    _error[304] = "<h1>304 Not Modified</h1>\n<p>The resource has not been modified since the last request.</p>";
    _error[400] = "<h1>400 Bad Request</h1>\n<p>Your request could not be understood by the server due to malformed syntax.</p>";
    _error[401] = "<h1>401 Unauthorized</h1>\n<p>Authentication is required to access this resource.</p>";
    _error[403] = "<h1>403 Forbidden</h1>\n<p>You are not authorized to view this resource.</p>";
    _error[404] = "<h1>404 Not Found</h1>\n<p>The page you are looking for could not be found.</p>";
    _error[405] = "<h1>405 Method Not Allowed</h1>\n<p>The HTTP method used is not supported for this resource.</p>";
    _error[406] = "<h1>406 Not Acceptable</h1>\n<p>The requested resource is not available in a format acceptable to your client.</p>";
    _error[408] = "<h1>408 Request Timeout</h1>\n<p>The server timed out waiting for your request.</p>";
    _error[409] = "<h1>409 Conflict</h1>\n<p>Your request conflicts with the current state of the server.</p>";
    _error[410] = "<h1>410 Gone</h1>\n<p>The requested resource is no longer available on the server and has no forwarding address.</p>";
    _error[411] = "<h1>411 Length Required</h1>\n<p>The request did not specify the length of its content, which is required by the resource.</p>";
    _error[413] = "<h1>413 Payload Too Large</h1>\n<p>The request is larger than the server is willing or able to process.</p>";
    _error[414] = "<h1>414 URI Too Long</h1>\n<p>The URI provided was too long for the server to process.</p>";
    _error[415] = "<h1>415 Unsupported Media Type</h1>\n<p>The server does not support the media type provided in the request.</p>";
    _error[429] = "<h1>429 Too Many Requests</h1>\n<p>You have sent too many requests in a given amount of time. Please try again later.</p>";
    _error[500] = "<h1>500 Internal Server Error</h1>\n<p>An unexpected error occurred on the server.</p>";
    _error[501] = "<h1>501 Not Implemented</h1>\n<p>The server does not support the functionality required to fulfill the request.</p>";
    _error[502] = "<h1>502 Bad Gateway</h1>\n<p>The server received an invalid response from the upstream server.</p>";
    _error[503] = "<h1>503 Service Unavailable</h1>\n<p>The server is currently unable to handle the request due to temporary overload or maintenance.</p>";
    _error[504] = "<h1>504 Gateway Timeout</h1>\n<p>The server did not receive a timely response from the upstream server.</p>";
    _error[505] = "<h1>505 HTTP Version Not Supported</h1>\n<p>The server does not support the HTTP protocol version used in the request.</p>";
}
