/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaxBodySize.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/06 19:23:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MaxBodySize.hpp"
#include "utils.hpp"
#include <list>

using namespace std;

size_t	KB = 1024;
size_t	MB = KB * 1024;
size_t	GB = MB * 1024;

void	MaxBodySize::setMaxBodySize(string maxBodySize){
	if (maxBodySize.empty())
		return ;
	if (maxBodySize.find("client_max_body_size") == string::npos)
		return ;
	normalize(maxBodySize, "client_max_body_size");
	if (maxBodySize.empty())
		return ;
	getFormatValue(maxBodySize);
	setValue();	
	_instances++;
}

std::size_t	MaxBodySize::getMaxBodySize(){
	return _maxBodySize;
}

void	MaxBodySize::getFormatValue(string maxBodySize){
	size_t i = 0;

	while (i < maxBodySize.length() && std::isdigit(maxBodySize[i])){
		_value += maxBodySize[i];
		i++;
	}
	while (i != maxBodySize.length()){
		_format += maxBodySize[i];
		i++;
	}
	trim(_format);
}

void	MaxBodySize::setValue(){
	size_t value;

	_format = toUpper(_format);
	value = toulong(_value);

	if (_format.empty()){
		_maxBodySize = value;
		return ;
	}
	if (_format[0] == 'K')
		_maxBodySize = value * KB;
	else if (_format[0] == 'M')
		_maxBodySize = value * MB;
	else if (_format[0] == 'G')
		_maxBodySize = value * GB;
	else
		throw runtime_error("unknown unit of measurement");;
}

MaxBodySize &MaxBodySize::operator=(MaxBodySize const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_format = origin._format;
		this->_maxBodySize = origin._maxBodySize;
		this->_value = origin._value;
	}
	return *this;
}

MaxBodySize::MaxBodySize(): DirectivesBase(), _maxBodySize(1000000){}