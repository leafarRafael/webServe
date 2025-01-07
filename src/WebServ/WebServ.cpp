/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServ.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:02 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/07 16:24:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <unistd.h>
#include "WebServ.hpp"
#include "Request.hpp"
#include "utils.hpp"
#include "ABody.hpp"
#include "DataBody.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Log.hpp"
#include "SignalHandler.hpp"

using namespace std;

WebServ::~WebServ(){
	std::list<Client *>::iterator it, ite;

	it = _client.begin();
	ite = _client.end();
	while (it != ite){
		delete *it;
		it++;
	}
	_client.clear();

};
WebServ::WebServ(std::list<Server> servers) : ParseRequest(), Epoll(), _servers(servers){
	initEpollStruct();
	createEpoll();
	addSocketsToEpoll(_servers);
}

void	WebServ::loopingEvent() {
	while(true)
	{
		_nfds = epoll_wait(_epollFd, _events, MAX_EVENTS, 1000);
		if (_nfds == 0){
			checkTimeOut();
			continue ;
		}
		for(int index_epoll = 0; index_epoll < _nfds; index_epoll++){
			if (_events[index_epoll].events == EPOLLIN){
				if (isNewClient(_events[index_epoll].data.fd))
					continue ;
				receiveCustomerData(_events[index_epoll].data.ptr);
			}
			else
				manangerResponse(_events[index_epoll].data.ptr);
		}
		if (SignalHandler::breakLooping())
			break ;
	}
}

bool	WebServ::isNewClient(int fd){
	int						fdClient;
	list<Server>::iterator	it;

	for(it = _servers.begin(); it != _servers.end(); ++it) {
		if (fd == it->getSocketFd()) {
			fdClient = accept(it->getSocketFd(), 0, 0);
			if (fdClient == -1)
				throw (runtime_error("error: epoll_ctl()"));
			std::string	serverRef;
			if ((serverRef = it->getDataServerOBJ().getServerName()).empty())
				serverRef = it->getIpPort();
			Log::message("Connection accepted:",
				"Client fd:", intToString(fdClient).c_str(),
				"Server:", serverRef.c_str(), 0);
			Client *client = new Client(*it, fdClient);
			client->setMaxSize(it->getMaxBodySize());
			_client.push_back(client);
			epoll_CTRL(fdClient, EPOLLIN, EPOLL_CTL_ADD, (void*)(client));
			return (true);
		}
	}
	return (false);	
}

void	WebServ::receiveCustomerData(void *ptr){
	Client *client;
	
	client = (Client *)ptr;
	if (not client->getRequest())
	{
		Request *request = setBufferSocketFd(client);
		if (request)
		{
			client->setRequest(request);
			if (request->getParserError() == -1)
				removeClient(request, client);
			else
				epoll_CTRL(client->getFdClient(), EPOLLOUT, EPOLL_CTL_MOD, (void*)(client));
		}
	}
}

void	WebServ::manangerResponse(void *ptr){
	Client	*client = (Client *)ptr;
	Request	*request = client->getRequest();
	Server	server = client->getServer();
	server.response(client->getFdClient(), request);
	removeClient(request, client);
}

void	WebServ::checkTimeOut(){
	std::list<Client*>::iterator it = _client.begin();
	char	c;

	if(it == _client.end())
		return ;
	while (it != _client.end()){
		if ((*it)->timeOut() || recv((*it)->getFdClient(), &c, 1, MSG_PEEK) <= 0){
			Client	 *client;
			Log::message("Client fd:", intToString((*it)->getFdClient()).c_str(),
				"was disconnected due to TimeOut.", 0);
			Request *request = (Request *)(*it)->getRequest();
			removeFdToParseRequest((*it)->getFdClient());
			epoll_CTRL((*it)->getFdClient(), EPOLLOUT, EPOLL_CTL_DEL, NULL);
			close((*it)->getFdClient());
			if (request)
				delete request;
			client = (*it);
			it = _client.erase(it);
			delete client;
		}else
			it++;
	}
}

int		WebServ::removeClient(Request *request, Client *client){
	removeFdToParseRequest(client->getFdClient());
	epoll_CTRL(client->getFdClient(), EPOLLOUT, EPOLL_CTL_DEL, NULL);
	close(client->getFdClient());
	ereaseClient(client);
	delete request;
	delete client;
	return 0;
}

void	WebServ::ereaseClient(Client *client){
	std::list<Client*>::iterator it;

	it = find(_client.begin(), _client.end(), client);
	if (it == _client.end())
		return ;
	_client.erase(it);
}
