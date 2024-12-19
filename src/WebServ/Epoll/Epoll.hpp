/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Epoll.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:54:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 15:24:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/epoll.h>
#include "Server.hpp"

class Epoll{
	protected:
		int			_nfds, _epollFd;
		epoll_event	_events[80];
		void	createEpoll();
		void	initEpollStruct();
		void	addSocketsToEpoll(std::list<Server> servers);
		void	epoll_CTRL(int clientFd, int event, int flagCTLR, void *ptr);
		Epoll();
		~Epoll();

};