/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 15:07:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Delete.hpp"
#include "ErrorDefault.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include "utils.hpp"
#include "ReasonPhrase.hpp"

Delete::Delete(): AMethods(){}

Delete::~Delete(){}

HTTP	Delete::createHTTP(){
	std::string	buffer;
	std::string file;

	if (_errorRequest)
		processError(_errorRequest);
	else if (not _returnIndex.empty())
		processReturnDirective();
	else if (not _allowMethods.isAllowedMethod(_method)){
		processError(403);
		return getHTTP();
	}
	file = _pathTraslated + getFile(_path_html);
	if (pathIsFile(file)){
		if (remove(file.c_str()) == 0){
			_statusCode = 204;
			_reasonPhrase = ReasonPhrase::getPhrase(204);
		}
		else
			processError(404);
	}else
		processError(400);
	return getHTTP();
}

int		Delete::pathIsFile(const std::string& path)
{
	struct stat s;

	if (stat(path.c_str(), &s) != 0)
		return -1;
	if (S_ISDIR(s.st_mode))
		return 0;
	if (S_ISREG(s.st_mode))
		return 1;
	return 0;
}