/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mime.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:05:36 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 13:07:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mime.hpp"
#include <iostream>
#include "utils.hpp"
#include "algorithm"

Mime::Mime(){initMimes();}
Mime::~Mime(){}

	
std::string	Mime::_types[7] = {
	"text/",
	"image/",
	"audio/",
	"video/",
	"application/",
	"multipart/",
	"font/",
};

void Mime::initMimes(){
	std::ifstream file(MIMES_LIST, std::ios::in | std::ios::binary);
	if(!file)
		throw (std::runtime_error(std::strerror(errno)));
	std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	_buffer = buffer;
	validCurlyBraces();
	addMimes();
}

void	Mime::addMimes(){
	for(std::size_t i = 0; i < 7;i++){
		std::size_t	pos;
		pos = _buffer.find(_types[i]);
		if (pos != std::string::npos){
			std::string mime = takeMime(pos);
			normalizeMime(mime);
			addMime(mime, _types[i]);
		}
	}
}

std::string	Mime::takeMime(std::size_t pos){
	std::string	buffer;
	std::size_t i = pos;
	while(_buffer[i] != '}')
		i++;
	buffer = _buffer.substr(pos, i);
	_buffer.erase(pos, i);
	return buffer;
}

void	Mime::normalizeMime(std::string &mime){
	trim(mime);
	removeToString(mime, "{");
	removeToString(mime, "}");
}

void		Mime::validCurlyBraces(){
	std::size_t	index = 0, openBraces = 0, closeBraces = 0;
	
	while (index < _buffer.length()){
		if (_buffer[index] == '{')
			openBraces++;
		if (_buffer[index] == '}')
			closeBraces++;
		if (closeBraces > openBraces)
			throw (std::runtime_error("Check the curly braces in MIMES.TXT."));
		index++;
	}
	if (closeBraces != openBraces)
		throw (std::runtime_error("Check the curly braces in MIMES.TXT."));
}

void	Mime::addMime(std::string &mime, std::string type){
	std::list<std::string> 				tokens;
	std::list<std::string>::iterator	it;
	std::string							key;

	tokens = split<std::string, char, std::list<std::string> >(mime, '\n');
	it = find(tokens.begin(), tokens.end(), type);
	if (it == tokens.end())
		throw (std::runtime_error("Error to tokenize mimes."));
	for(std::list<std::string>::iterator its = tokens.begin(); its != tokens.end(); its++){
		trim(*its);
		removeToString(*its, ";");
	}
	key = *it;
	tokens.erase(it);
	std::list<std::string>::iterator itTok;
	for(itTok = tokens.begin(); itTok != tokens.end(); itTok++){
		_mimes[*itTok] = key + *itTok;
	}
}

std::string	Mime::getMime(std::string path){
	std::string fileExtension = getExtension(path);

	if (not _mimes.count(fileExtension))
		return std::string();
	return _mimes[fileExtension];	
}

std::string	Mime::getExtension(std::string path){
	std::list<std::string>	tokens;

	if (path == "/")
		return "html";
	tokens = split<std::string, char, std::list<std::string> >(path, '.');
	if (tokens.empty())
		return "html";
	return tokens.back();
}