/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Epoll.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:57:33 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 12:00:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Epoll.hpp"
#include <stdexcept>
#include <cstring>

using namespace std;

Epoll::Epoll():_nfds(0), _epollFd(0){}
Epoll::~Epoll(){}

void	Epoll::addSocketsToEpoll(list<Server> servers) {
	struct epoll_event		ev;
	list<Server >::iterator it;

	for (it = servers.begin(); it != servers.end(); ++it) {
		memset(&ev, 0, sizeof(ev));
		ev.events = EPOLLIN;
		ev.data.fd = it->getSocketFd();
		if (epoll_ctl(_epollFd, EPOLL_CTL_ADD, ev.data.fd, &ev) == -1)
			throw (runtime_error("error: epoll_ctl()"));
	}
}

void	Epoll::initEpollStruct(){
	for(int i = 0; i < 80; i++)
		std::memset(&_events[i], 0, sizeof(_events[i]));
	_epollFd = 0;
}

void	Epoll::createEpoll(){
	if ((_epollFd = epoll_create1(EPOLL_CLOEXEC)) == -1)
		throw std::runtime_error("error: epoll_create1()");
}

void	Epoll::epoll_CTRL(int clientFd, int event, int flagCTLR, void *ptr){
	struct epoll_event ev;

	ev.data.ptr = ptr;
	ev.events = event;
	if (epoll_ctl(_epollFd, flagCTLR, clientFd, &ev) == -1)
		throw (runtime_error("error: epoll_ctl()"));
}