/* ************************************************************************** */
/*                                                                            */

/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:41:42 by rbutzke           #+#    #+#             */
/*   Updated: 2024/11/14 08:06:22 by rbutzke          ###   ########.fr       */
/*   Updated: 2024/11/12 19:46:16 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Webserv.hpp"
#include "Server.hpp"
#include "Parser.hpp"
#include "Conf.hpp"
#include "Handler.hpp"
#include "defines.hpp"
#include "ParseConf.hpp"

#include "Settings.hpp"

using namespace std;

int main(int ac, char **av)
{
/* 	std::list<Server>	servers;
	std::string error;

	ParseConf parse;
	try{
		if (ac == 2)
			servers = parse.parseFileConf(av[1]);
	}catch(std::exception &e){
		cout << e.what() << "\n";
		exit(1);
	}

	std::cout << "IP: " << servers.front().getIP() << '\n';
	std::cout << "Port: " << servers.front().getPort() << '\n';
	std::cout << "ErrorPage: " << servers.front().getErrorPage(404) << '\n';
	std::cout << "ServerName: " << servers.front().getServerName() << '\n';
	std::cout << "MaxBody: " << servers.front().getMaxBodySize() << '\n';
	std::cout << "Root: " << servers.front().getRoot() << '\n';
	std::cout << "Index: " << servers.front().getIndex() << '\n';
	
	
	std::cout << "\n/////////////////////////////location /image/ ///////////////////////////////////////////////////\n\n";
	std::cout << "getPathLocation: " << servers.front().getLocation("/imagens/").getPathLocation() << '\n';
	std::cout << "isAllowedMethod(POST): " << servers.front().getLocation("/imagens/").isAllowedMethod("POST") << '\n';
	std::cout << "isAllowedMethod(GET) " << servers.front().getLocation("/imagens/").isAllowedMethod("GET") << '\n';
	std::cout << "getAutoIndexBool() " << servers.front().getLocation("/imagens/").getAutoIndexBool() << '\n';
	std::cout << ".getMaxBodySize()  " << servers.front().getLocation("/imagens/").getMaxBodySize() << '\n';
	std::cout << "getIndex() " << servers.front().getLocation("/imagens/").getIndex() << '\n';
	std::cout << "getRoot() " << servers.front().getLocation("/imagens/").getRoot() << '\n';
	
	
	
	std::cout << "\n/////////////////////////////location /update/ ///////////////////////////////////////////////////\n\n";
	std::cout << "getPathLocation: " << servers.front().getLocation("/upload/").getPathLocation() << '\n';
	std::cout << "isAllowedMethod(POST): " << servers.front().getLocation("/upload/").isAllowedMethod("POST") << '\n';
	std::cout << "isAllowedMethod(GET) " << servers.front().getLocation("/upload/").isAllowedMethod("GET") << '\n';
	std::cout << "getAutoIndexBool() " << servers.front().getLocation("/upload/").getAutoIndexBool() << '\n';
	std::cout << ".getMaxBodySize()  " << servers.front().getLocation("/upload/").getMaxBodySize() << '\n';
	std::cout << "getIndex() " << servers.front().getLocation("/upload/").getIndex() << '\n';
	std::cout << "getRoot() " << servers.front().getLocation("/upload/").getRoot() << '\n'; */

	
	if (ac <= 2) {
		try {
			Conf cf;
			Parser::parser(cf, (ac == 1 ? "conf/default.conf": av[1]));
			manager.setting();
			manager.loopingEvent();
		} catch (const exception &e) {
			cerr << e.what() << endl;
		}
	} else {
		cerr << "usage: ./webserv <path to configuration file> or just ./webserv" << endl;
		return (FAIL);
	}
	return (SUCCESS);
}