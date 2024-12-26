/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:08:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 12:11:33 by rbutzke          ###   ########.fr       */
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

		void			setDataServer(std::string serverDirective);
		void			setLocation(std::string location);
		
		std::string		getIP();
		std::string		getPort();

		void			setMaxBodySize(std::string maxBodySize);
		std::size_t		getMaxBodySize();

		DataLocation	getDataLocationOBJ(std::string	path);
		DataServer		getDataServerOBJ();
};
