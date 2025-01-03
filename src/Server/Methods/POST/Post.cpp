/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Post.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 18:29:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Post.hpp"
#include "ErrorDefault.hpp"
#include "utils.hpp"
#include "ReasonPhrase.hpp"

Post::Post(): AMethods(){}

Post::~Post(){}

HTTP	Post::createHTTP(){
	if (_errorRequest)
		processError(_errorRequest);
	else if (not _returnIndex.empty())
		processReturnDirective();
	else if (not _path_cgi.empty())
		processCGI();
	else if (not _path_html.empty())
		processFile();
	else
		processError(404);
	return getHTTP();
}

void	Post::processCGI(){
	int	status = 0;

	_bufferBody = commonGatewayInterface();
	if (_bufferBody.find("STATUS CODE: ") != std::string::npos){
		status = getErrorValue();
		if (status > 200)
			processError(status);
		else{
			_bufferBody.clear();
			_statusCode = status;
			_reasonPhrase = ReasonPhrase::getPhrase(status);
		}
	}
}
