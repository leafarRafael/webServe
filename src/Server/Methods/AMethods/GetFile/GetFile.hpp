/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetFile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:15:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 15:09:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <sys/types.h>
#include <dirent.h>

class GetFile{
	private:
		GetFile(){};
		~GetFile(){};
	
	public:
		static std::string getBufferDirectory(DIR *directory, std::string &path);
		static std::string getBufferFile(std::string path);
};