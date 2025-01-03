/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetFile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:15:56 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 13:12:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <sys/types.h>
#include <dirent.h>

#define FILE_ADDR "src/Server/Methods/AMethods/GetFile/directory.html"
#define REPLACEMENT_POIT "#*REPLACEMENT_POIT*#"
#define HTML_TO_SUBDIRECTORY "<li><span class=\"toggle\"></span><span>"

class GetFile{
	private:
		GetFile(){};
		~GetFile(){};
		static std::string createFile(std::string fileName);
		static std::string creatNewSubDirectory(DIR *directory, std::string &path);
	
	public:
		static std::string getBufferDirectory(DIR *directory, std::string &path);
		static std::string getBufferFile(std::string path);
};