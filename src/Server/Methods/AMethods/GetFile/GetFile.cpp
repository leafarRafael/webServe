/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetFile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:19:23 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 13:12:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetFile.hpp"
#include "unistd.h"
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "utils.hpp"
#include <list>

std::string GetFile::getBufferDirectory(DIR *directory, std::string &path){
	std::string		dataDirectoryHTML;
	std::string		html;
	std::size_t		pos;

	dataDirectoryHTML  = creatNewSubDirectory(directory, path);
	if (dataDirectoryHTML.empty())
		return dataDirectoryHTML;
	html = getBufferFile(FILE_ADDR);
	pos = html.find(REPLACEMENT_POIT);
	if (pos == std::string::npos)
		return std::string();
	html.replace(pos, std::string(REPLACEMENT_POIT).length(), dataDirectoryHTML);
	return html;
}

std::string GetFile::creatNewSubDirectory(DIR *directory, std::string &path){
	std::ostringstream	html;
	struct dirent		*dirent;
	std::string			pathName = "/";

	pathName += split<std::string, char, std::list<std::string> >(path, '/').back();	
	html << HTML_TO_SUBDIRECTORY << pathName << "</span><ul>";
	while ((dirent = readdir(directory)) != NULL)
	{
		if (dirent->d_name[0] != '.')
		{
			std::string buffer = dirent->d_name;
			if (dirent->d_type == DT_DIR){
				std::string subDirectory = path + buffer + "/" ;
				DIR *dir = opendir(subDirectory.c_str());
				if (dir != NULL){
					html << creatNewSubDirectory(dir, subDirectory);
					closedir(dir);
				}
			}
			else
				html << createFile(buffer);
		}
	}
	html << "</ul></li>";
	return html.str();
}

std::string GetFile::createFile(std::string fileName){
	std::string 		htlmOpenTag = "<li><span>";
	std::string 		htlmCloseTag = "</span></li>";
	std::ostringstream	html;

	html << htlmOpenTag << fileName << htlmCloseTag;
	return html.str();
}

std::string GetFile::getBufferFile(std::string path){
	std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);

	if(!file)
		return std::string();
	return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());	
}