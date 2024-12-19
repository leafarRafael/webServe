/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataLocation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:08:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 17:16:47 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataLocation.hpp"

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Setters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void DataLocation::setPathLocation(std::string pathLocation){
	_pathLocation.setPathLocation(pathLocation);
}

void DataLocation::setRoot(std::string root){
	_root.setRoot(root);
}

void DataLocation::setIndex(std::string index){
	_index.setIndex(index);
}

void DataLocation::setErrorPage(std::string errorPage){
	_errorPage.setErrorPage(errorPage);
}

void DataLocation::setMaxBodySize(std::string maxBodySize){
	_maxBodySize.setMaxBodySize(maxBodySize);
}

void DataLocation::setAutoIndex(std::string autoIndex){
	_autoIndex.setAutoIndex(autoIndex);
}

void DataLocation::setAllowMethods(std::string allowMethods){
	_allowMethods.setAllowMethods(allowMethods);
}

void DataLocation::setReturn(std::string returnIndex){
	_returnIndex.setReturn(returnIndex);
}

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string DataLocation::getPathLocation(){
	return _pathLocation.getPathLocation();
}

std::string DataLocation::getRoot(){
	return _root.getRoot();
}

std::string DataLocation::getIndex(){
	return _index.getIndex();
}

std::string DataLocation::getErrorPage(int errorCode){
	return _errorPage.getErrorPage(errorCode);
}

std::size_t	DataLocation::getMaxBodySize(){
	return _maxBodySize.getMaxBodySize();
}

bool		DataLocation::getAutoIndexBool(){
	return _autoIndex.getAutoIndexBool();
}

bool		DataLocation::isAllowedMethod(std::string method){
	return _allowMethods.isAllowedMethod(method);
}

std::string DataLocation::getReturn(){
	return _returnIndex.getReturn();
}
