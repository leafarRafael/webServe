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
#include "WebServ.hpp"
#include "Server.hpp"
#include "ParseConf.hpp"
#include "Settings.hpp"
#include <csignal>
#include "SignalHandler.hpp"

using namespace std;


int main(int ac, char **av){
	std::list<Server>	servers;
	ParseConf			parse;
	SignalHandler::configSignal();
	try
	{
		if (ac == 2)
			servers = parse.parseFileConf(av[1]);
		else if (ac == 1){
			servers = parse.parseFileConf("fileConf/default.conf");
		}
		else
			return 1;
		WebServ	web(servers);
		web.loopingEvent();
	}
	catch(std::exception &e)
	{
		cout << e.what() << "\n";
	}
}