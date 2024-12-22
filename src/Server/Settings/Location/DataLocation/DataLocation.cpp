/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataLocation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:08:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 18:21:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataLocation.hpp"
#include <iostream>
////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Setters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void DataLocation::setPathLocation(std::string pathLocation){
	_pathLocation.setPathLocation(pathLocation);
	_instances++;
}

void DataLocation::setRoot(std::string root){
	_root.setRoot(root);
	_instances++;
}

void DataLocation::setIndex(std::string index){
	_index.setIndex(index);
	_instances++;
}

void DataLocation::setErrorPage(std::string errorPage){
	_errorPage.setErrorPage(errorPage);
	_instances++;
}

void DataLocation::setMaxBodySize(std::string maxBodySize){
	_maxBodySize.setMaxBodySize(maxBodySize);
	_instances++;
}

void DataLocation::setAutoIndex(std::string autoIndex){
	_autoIndex.setAutoIndex(autoIndex);
	_instances++;
}

void DataLocation::setAllowMethods(std::string allowMethods){
	_allowMethods.setAllowMethods(allowMethods);
	_instances++;
}

void DataLocation::setReturn(std::string returnIndex){
	_returnIndex.setReturn(returnIndex);
	_instances++;
}

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

bool		DataLocation::empty(){
	if (_instances)
		return 0;
	return 1;
}

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

DataLocation &DataLocation::operator=(DataLocation const &origin){
	if(this != &origin){
		this->_instances = origin._instances;
		this->_pathLocation = origin._pathLocation;
		this->_root = origin._root;
		this->_index = origin._index;
		this->_errorPage = origin._errorPage;
		this->_maxBodySize = origin._maxBodySize;
		this->_autoIndex = origin._autoIndex;
		this->_allowMethods = origin._allowMethods;
		this->_returnIndex = origin._returnIndex;
	}
	return *this;
}

PathLocation 	DataLocation::getPathLocationOBJ(){
	return this->_pathLocation;
}

Root		 	DataLocation::getRootOBJ(){
	return this->_root;
}

Index 			DataLocation::getIndexOBJ(){
	return this->_index;
}

ErrorPage		DataLocation::getErrorPageOBJ(){
	return this->_errorPage;
}

MaxBodySize		DataLocation::getMaxBodySizeOBJ(){
	return this->_maxBodySize;
}

AutoIndex		DataLocation::getAutoIndexOBJ(){
	return this->_autoIndex;
}

AllowMethods	DataLocation::getAllowedMethodOBJ(){
	return this->_allowMethods;
}

Return			DataLocation::getReturnOBJ(){
	return this->_returnIndex;
}
