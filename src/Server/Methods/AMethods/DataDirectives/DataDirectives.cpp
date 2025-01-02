/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataDirectives.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:47:45 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:55:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataDirectives.hpp"
#include "FindLocation.hpp"

void	DataDirectives::selectDirectives(Server &server, Request &request){
	DataLocation	dataLocation;
	DataServer		dataServer;

	dataServer = server.getDataServerOBJ();
	addGlobalDirectives(dataServer);
	
	dataLocation = findDataLocation(server, request);
	if (not dataLocation.empty()){
		addLocationDirectives(dataLocation);
	}
}

void	DataDirectives::addGlobalDirectives(DataServer dataServer){
	_root = dataServer.getRootOBJ();
	_index = dataServer.getIndexOBJ();
	_errorPage = dataServer.getErrorPageOBJ();
	_errorPage = dataServer.getErrorPageOBJ();
	_allowMethods = dataServer.getAllowMethodsOBJ();
	_allowMethods = dataServer.getAllowMethodsOBJ();
	_returnIndex = dataServer.getReturnOBJ();
}

void	DataDirectives::addLocationDirectives(DataLocation dataLocation){
	_index = dataLocation.getIndexOBJ();
	_autoIndex = dataLocation.getAutoIndexOBJ();
	if (not dataLocation.getReturnOBJ().empty())
		_returnIndex = dataLocation.getReturnOBJ();
	if (not dataLocation.getAllowedMethodOBJ().empty())
		_allowMethods = dataLocation.getAllowedMethodOBJ();
	if (not dataLocation.getRootOBJ().empty())
		_root = dataLocation.getRootOBJ();
	if (not dataLocation.getErrorPageOBJ().empty())
		_errorPage = dataLocation.getErrorPageOBJ();
	if (not dataLocation.getMaxBodySizeOBJ().empty())
		_maxBodySize = dataLocation.getMaxBodySizeOBJ();
}

DataLocation	DataDirectives::findDataLocation(Server &server, Request &request){
	return FindLocation::findLocation(server, request);
}

