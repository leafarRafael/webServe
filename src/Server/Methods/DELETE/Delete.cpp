/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:15:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/31 13:43:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Delete.hpp"
#include "ErrorDefault.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include "utils.hpp"

Delete::Delete(): AMethods(){}

Delete::~Delete(){}

HTTP	Delete::createHTTP(){
	std::string	buffer;
	std::string file;
	
	if (not _allowMethods.isAllowedMethod(_method)){
		std::string buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(403));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(403);
		_statusCode = 403;
		_statusMensagen = "Forbidden";
		return getHTTP();
	}
	file = _pathTraslated + getFile(_path_html);
	if (pathIsFile(file)){
		if (remove(file.c_str()) == 0){
			_statusCode = 204;
			_statusMensagen = "No Content";
		}
		else{
			buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
			if(buffer.empty())
				buffer = ErrorDefault::getErrorDefault(404);
			_statusCode = 404;
			_statusMensagen = "not Found";
		}
	}else{
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(400));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(400);
		_statusCode = 400;
		_statusMensagen = "Forbidden";
		
	}
	return getHTTP();
}

void	Delete::processFILE(){
	std::string		path;
	std::string		buffer;
	std::string		file;

	file = getFile(_path_html);
	path = _root.getRoot();
	path += file;
	if (file.size() == 1 && file[0] == '/'){
		path += _index.getIndex();
	}
	buffer = getBufferFile(path);
	if (buffer.empty()){
		buffer = getBufferFile(_root.getRoot() + _errorPage.getErrorPage(404));
		if(buffer.empty())
			buffer = ErrorDefault::getErrorDefault(404);
	}
	_contentType = getMime(_path_html);
	_bufferBody = buffer;
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