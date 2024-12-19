/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:37:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 17:34:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Socket.hpp"
# include "Response.hpp"
# include <string>
# include <map>
# include "Settings.hpp"

class Request;
class Directive;

class Server : public Socket, public Response, public Settings {
	private:
		std::map<int, Request *>			fdClient;
		int									_socketFd;

	public:
		Server();
		~Server();
		void			response(int fd, Request *request);
};
