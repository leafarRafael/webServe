/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:22:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"
#include "utils.hpp"

using namespace std;

void	Root::setRoot(string root){
	if (root.empty())
		return ;
	if (root.find("root") == string::npos)
		return ;
	normalize(root, "root");
	list<string> tokens = split<string, char, list<string> >(root, ' ');
	if (tokens.size() != 1)
		throw (runtime_error("Error: multiple assignments for root directive"));
	_root = tokens.front();
	_instances++;
}

std::string	Root::getRoot(){
	return _root;
}

Root&Root::operator=(Root const &origin){
	if (this != &origin){
		DirectivesBase::operator=(origin);
		this->_root = origin._root;
	}
	return *this;
}

Root::Root() : DirectivesBase(){}