/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mime.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:04:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/20 12:37:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <cstring>

#define MIMES_LIST "src/MIMES/MIMES.txt"

typedef std::map<std::string, std::list<std::string> > MIMES;

class Mime{
	
	private:
		static std::string	_types[7];
		std::string			_buffer;
		void		initMimes();
		void		validCurlyBraces();
		void		addMimes();
		std::string	takeMime(std::size_t pos);
		void		addMime(std::string &mime, std::string type);
		void		normalizeMime(std::string &mime);

	protected:
		Mime();
		~Mime();
		MIMES		_mimes;
		/* std::string	getMime(std::string mime); */
};