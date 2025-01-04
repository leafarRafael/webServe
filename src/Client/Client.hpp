/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:22:08 by myokogaw          #+#    #+#             */
/*   Updated: 2025/01/04 15:59:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <ctime>
#include "Server.hpp"

class Server;
class Request;

class Client{
	private:
		Server			_server;
		Request			*_request;
		std::time_t		_startTime;
		int				_socketFdClient;
		long long int	_maxSize;

	public:
	    bool operator==(const Client& other) const {return (this == &other);}
		Client(Server &server, int fdClient);
		~Client();

		Server			getServer(void) const;
		Request			*getRequest(void) const;
		void			setRequest(Request *request);
		int				getFdClient(void) const;
		void			setMaxSize(long long int maxSize);
		long long int	getMaxSize() const;
		
		int		timeOut(void);
};
