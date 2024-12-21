/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServ.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/20 15:54:53 by rbutzke          ###   ########.fr       */
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

using namespace std;

WebServ::~WebServ() {};
WebServ::WebServ(std::list<Server> servers) : ParseRequest(), Epoll(), _servers(servers){
	initEpollStruct();
	createEpoll();
	addSocketsToEpoll(_servers);
}

void	WebServ::loopingEvent() {
	while(true)
	{
		_nfds = epoll_wait(_epollFd, _events, MAX_EVENTS, 1000);
		if (_nfds == 0)
		{
			checkTimeOut();
			continue ;
		}
		for(int index_epoll = 0; index_epoll < _nfds; index_epoll++)
		{
			if (_events[index_epoll].events == EPOLLIN)
			{
				if (isNewClient(_events[index_epoll].data.fd))
					continue ;
				receiveCustomerData(_events[index_epoll].data.ptr);
			}
			else
			{
				manangerResponse(_events[index_epoll].data.ptr);
			}
		}
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

	if(it == _client.end())
		return ;
	while (it != _client.end()){
		if ((*it)->timeOut()){
			Request *request = (Request *)(*it)->getRequest();
			removeFdToParseRequest((*it)->getFdClient());
			close((*it)->getFdClient());
			if (request)
				delete request;
			it = _client.erase(it);
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

void exemploRequestParseado(Request *request){
	cout << "Method: " << request->getMethod() << "\n";
	cout << "Host: " << request->getHost() << "\n";
	cout << "Path: " << request->getPath() << "\n";
	cout << "Version: " << request->getVersion() << "\n";

	putMapList(request->getAllHeader());
	cout << "\n";
 	ABody *ptr = request->getBody();
	if (ptr != NULL){
		list<DataBody>	body;
	 	body = ptr->getDataBody();
		for (list<DataBody>::iterator it = body.begin(); it != body.end(); it++){
			putMapList(it->getAllHeaders());
			list<string> temp = it->getHeaders("Content-Type");
			if (not temp.empty()){
				list<string> t = it->getHeaders("Content-Disposition");
				list<string>::iterator i = t.end();
				i--;
				i->erase(0, 10);
				i->erase(i->size()-1, 1);
				ofstream	outfile(i->c_str());
				if (!outfile.is_open())
					cout << "nao abriu\n";
				if(it->getContent().length() > 60)
					outfile << it->getContent();
			}
		}
	}
}