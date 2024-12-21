/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:37:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/20 14:12:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <map>
# include "Socket.hpp"
# include "Response.hpp"
# include "Settings.hpp"
# include "Mime.hpp"
# include "HTTP.hpp"

class AMethods;
class Request;
class Directive;

class Server : public Socket, public Response, public Settings , public Mime{
	private:
		std::map<int, Request *>			fdClient;
		int									_socketFd;
		AMethods *defineMethods(std::string method);

	public:
		Server();
		~Server();
		void			response(int fd, Request *request);
};
