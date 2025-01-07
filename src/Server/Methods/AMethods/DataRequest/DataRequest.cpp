/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:50:25 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/07 12:29:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataRequest.hpp"

#include <iostream>

std::string	DataRequest::extensionCGI[7] = {
	".py", ".php", ".sh", ".bash", ".pl", ".rb", ".cgi"
};

DataRequest::DataRequest(){
	_path_html = "";
	_path_cgi = "";
	_path_info = "";
	_query_string = "";
	_method = "";
	_body = "";
	_content_length = "";
	_content_type = "";
	_http_version = "";
	_isCGI = false;
	_errorRequest = 0;
	_isAllowMethodInPathTraslated = false;
	_existeTraslated = false;
	_maxBodyTraslated = 0;
	_requestContentLenght = 0;
}

DataRequest::~DataRequest(){}

void	DataRequest::setDateRequest(Request &request){
	_errorRequest = request.getParserError();
	_method = request.getMethod();
	_http_version = request.getVersion();
	_content_length = joinHeaders(request.getHeader("Content-Length"));
	_content_type = joinHeaders(request.getHeader("Content-Type"));
	ABody *body = request.getBody();
	if (body)
		_body = body->getDataBody().getContent();
	splitURL(request.getPath());
}

void	DataRequest::splitURL(std::string url){
	url = addQueryString(url);
	url = addPathInfo(url);
	addPathCGI(url);
}

std::string	DataRequest::addQueryString(std::string url){
	std::size_t pos;
	std::string	path;

	pos = url.find('?');
	if (pos == std::string::npos)
		return url;
	path = url.substr(0, pos);
	url.erase(0, pos+1);
	_query_string = url;
	return path;
}

std::string	DataRequest::addPathInfo(std::string url){
	std::size_t pos;
	std::string	path;
	int			i = 0;

	while(i < 7){
		pos = url.find(extensionCGI[i]);
		if (pos != std::string::npos)
			break ;
		i++;
	}
	if (pos == std::string::npos)
		return url;
	path = url.substr(0, pos + extensionCGI[i].length());
	url.erase(0, pos + extensionCGI[i].length() +1);
	_path_info = "/" + url;
	_isCGI = true;
	return path;
}

void DataRequest::addPathCGI(std::string url){
	std::string	delimiter = ".html";
	std::size_t pos = url.find(delimiter);
	if (pos == std::string::npos){
		if (url.find("/cgi/") != std::string::npos)
			_path_cgi = url;
		else
			_path_html = url;	
		return ;
	}
	_path_html = url.substr(0, pos + delimiter.size());
	url.erase(0, pos + delimiter.length() +1);
	if (url.find("cgi") != std::string::npos)
		_path_cgi = "/" + url;
}

std::string	DataRequest::joinHeaders(std::list<std::string> header){
	std::ostringstream	value;
	
	if (header.empty())
		return value.str();
	if (header.size() == 1)
		return header.front();
	std::list<std::string>::iterator it, temp = header.begin();
	temp++;
	for(it = header.begin(); it != header.end(); it++){
		value << *it;
		if (temp != header.end())
			value << ", ";
		temp++;
	}
	return value.str();
}

