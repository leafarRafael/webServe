/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:35:00 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:58:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataServer.hpp"

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Getters/////////////////////////////////
////////////////////////////////////////////////////////////////////////////

std::string DataServer::getErrorPage(int statusCode){
	return _errorPage.getErrorPage(statusCode);
}

std::string	DataServer::getIP(){
	return _listen.getIP();
}

std::string	DataServer::getPort(){
	return _listen.getPort();
}

std::string	DataServer::getServerName(){
	return _serverName.getServerName();
}

std::size_t	DataServer::getMaxBodySize(){
	return _maxBodySize.getMaxBodySize();	
}

std::string	DataServer::getRoot(){
	return _root.getRoot();
}

std::string	DataServer::getIndex(){
	return _index.getIndex();
}

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Methods Setters////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void		DataServer::setErrorPage(std::string error_page){
	_errorPage.setErrorPage(error_page);
}

void		DataServer::setListen(std::string listen){
	_listen.setListen(listen);
}

void		DataServer::setServerName(std::string serverName){
	_serverName.setServerName(serverName);
}

void		DataServer::setMaxBodySize(std::string maxBodySize){
	_maxBodySize.setMaxBodySize(maxBodySize);
}

void		DataServer::setRoot(std::string root){
	_root.setRoot(root);
}

void		DataServer::setIndex(std::string index){
	_index.setIndex(index);
}

void		DataServer::setReturn(std::string directiveReturn){
	_directiveReturn.setReturn(directiveReturn);
}

DataServer &DataServer::operator=(DataServer const &origin){
	if (this != &origin){
		this->_listen = origin._listen;
		this->_errorPage = origin._errorPage;
		this->_serverName = origin._serverName;
		this->_maxBodySize = origin._maxBodySize;
		this->_root = origin._root;
		this->_index = origin._index;
		this->_allowMethods = origin._allowMethods;
		this->_directiveReturn = origin._directiveReturn;
	}
	return *this;
}

DataServer::DataServer(){
	_allowMethods.setAllowMethods("allow_methods POST GET");
}

MaxBodySize	DataServer::getMaxBodySizeOBJ(){
	return this->_maxBodySize;
}

Root		DataServer::getRootOBJ(){
	return this->_root;
}

Index		DataServer::getIndexOBJ(){
	return this->_index;
}

ErrorPage	DataServer::getErrorPageOBJ(){
	return this->_errorPage;
}

ServerName	DataServer::getServerNameOBJ(){
	return this->_serverName;
}

AllowMethods DataServer::getAllowMethodsOBJ(){
	return this->_allowMethods;
}
Return		DataServer::getReturnOBJ(){
	return this->_directiveReturn;	
}