/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/05 19:02:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get.hpp"
#include "ErrorDefault.hpp"
#include "ReasonPhrase.hpp"

Get::Get(): AMethods(){}

Get::~Get(){}

HTTP	Get::createHTTP(){
	if (_errorRequest)
		processError(_errorRequest);
	else if (not _returnIndex.empty())
		processReturnDirective();
	else if (not _path_html.empty())
		processFile();
	else if (_path_html.empty() && not _path_cgi.empty())
		processCGI();
	else
		processError(404);
	return getHTTP();
}

void	Get::processCGI(){
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
	else{
		_statusCode = 200;
		_reasonPhrase = ReasonPhrase::getPhrase(200);
	}
}
