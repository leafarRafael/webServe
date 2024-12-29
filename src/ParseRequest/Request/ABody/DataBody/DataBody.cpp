/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBody.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:24:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 13:56:47 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBody.hpp"
#include "utils.hpp"

using namespace std;

DataBody::DataBody(){
	_content = "";
};

void	DataBody::setContent(string &value){
	this->_content.append(value);
}

void	DataBody::setContentApend(string value, size_t length){
	_content.append(value.c_str(), length);
}

string DataBody::getContent() const{
	return _content;
}

DataBody &DataBody::operator=(const DataBody & orin){
	if(this != &orin){
		this->_content = orin.getContent();
	}
	return *this;
}