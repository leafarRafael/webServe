/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectivesBase.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:45:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 09:47:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DirectivesBase.hpp"

DirectivesBase::~DirectivesBase(){}

DirectivesBase::DirectivesBase():_instances(0){}

DirectivesBase &DirectivesBase::operator=(DirectivesBase const &origin){
	if (this != &origin){
		this->_instances = origin._instances;
	}
	return *this;
}


bool	DirectivesBase::empty(){
	if (_instances)
		return false;
	return true;
};