/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Index.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 10:57:39 by rbutzke          ###   ########.fr       */
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

}

std::string	Index::getIndex(){
	return _index;
}

