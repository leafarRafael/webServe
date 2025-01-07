/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Epoll.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:54:09 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/07 16:39:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/epoll.h>
#include "Server.hpp"

#define EPOLL_MAX_STRUCT 256

class Epoll{
	protected:
		int			_nfds, _epollFd;
		epoll_event	_events[EPOLL_MAX_STRUCT];
		void	createEpoll();
		void	initEpollStruct();
		void	addSocketsToEpoll(std::list<Server> servers);
		void	epoll_CTRL(int clientFd, int event, int flagCTLR, void *ptr);
		Epoll();
		~Epoll();

};