/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:08:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:51:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Location.hpp"
#include "DataServer.hpp"

class DataLocation;

typedef	struct direct_method
{
	std::string	input;
	void (DataServer::*function)(std::string);

} direct_Method;

class Settings{

	private:
		static	direct_Method	_ptrMethods[6];
		DataServer				_directiveServer;
		Location				_directiverLocation;

		void	addServerDirective(std::list<std::string> &tokens);
		void	setDirective(std::string directive);

	public:
		Settings&operator=(Settings const &origin);

		void			setServerDirective(std::string serverDirective);
		void			setLocation(std::string location);
	

		void			setErrorPage(std::string error_page);
		std::string		getErrorPage(int statusCode);
		
		void			setListen(std::string listen);
		std::string		getIP();
		std::string		getPort();

		void			setServerName(std::string serverName);
		std::string		getServerName();

		void			setMaxBodySize(std::string maxBodySize);
		std::size_t		getMaxBodySize();

		void			setRoot(std::string root);
		std::string		getRoot();

		void			setIndex(std::string index);
		std::string		getIndex();
		
		DataLocation	getDataLocationOBJ(std::string	path);
		DataServer		getDataServerOBJ();
};
