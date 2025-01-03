/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Index.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:03:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Index.hpp"
#include "utils.hpp"

using namespace std;

void	Index::setIndex(string index){
	if (index.empty())
		return ;
	if (index.find("index") == string::npos)
		return ;
	normalize(index, "index");
	list<string> tokens = split<string, char, list<string> >(index, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for index directive"));
	_index = tokens.front();
	_instances++;
}

std::string	Index::getIndex(){
	return _index;
}

Index&Index::operator=(Index const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_index = origin._index;
	}
	return *this;
}

Index::Index(): DirectivesBase(){}