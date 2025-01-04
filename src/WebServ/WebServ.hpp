/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServ.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:19 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 15:30:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Server.hpp"
#include <sys/epoll.h>
#include <string>
#include <iterator>
#include <map>
#include <iostream>
#include "ParseRequest.hpp"
#include "Epoll.hpp"

# define MAX_EVENTS 10

class Client;
class ServerDirective;

class WebServ : public ParseRequest, public Epoll {
	private:
		std::list<Client *>					_client;
		std::list<Server>					_servers;

		void	manangerResponse(void *ptr);
		int		removeClient(Request *request, Client *client);
		bool	isNewClient(int fd);
		void	checkTimeOut();
		void	ereaseClient(Client *client);
		void	receiveCustomerData(void *ptr);

	public:
		~WebServ();
		WebServ(std::list<Server> servers);

		void	loopingEvent(void);
};

extern WebServ manager;
