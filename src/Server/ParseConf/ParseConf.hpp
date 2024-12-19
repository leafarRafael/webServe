/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseConf.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:28:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 10:46:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <fstream>
#include <list>
#include "Server.hpp"
#include "ParseValidation.hpp"
#include "ParseTokens.hpp"

class ParseConf:public ParseValidation, public ParseTokens{
	private:
		std::list<Server>			_server;
		std::string					_buffer;
		void	readFile(std::string fileConf);
		void	removeComments(std::string &buffer);
		void	validDirectives();
		void	initServers();
		void	setServerScope(std::string &serverDirectives, Server &server);
		void	setLocationScope(std::string &serverDirectives, Server &server);

	
	public:
		std::list<Server>	parseFileConf(std::string file);
};	