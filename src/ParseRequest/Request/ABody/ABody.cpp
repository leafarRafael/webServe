/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABody.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:13:34 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 14:02:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABody.hpp"

DataBody	ABody::getDataBody(){
	return _data;
}

void	ABody::setDataBody(DataBody &data){
	_data = data;
}

void	ABody::setLengthBody(size_t length){
	_lengthBody = length;
}
size_t	ABody::getLengthBody(){
	return _lengthBody;	
}