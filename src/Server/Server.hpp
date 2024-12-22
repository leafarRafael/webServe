/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:37:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:32:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <map>
# include "Socket.hpp"
# include "Settings.hpp"
# include "Mime.hpp"
# include "HTTP.hpp"

class AMethods;
class Request;
class Directive;

class Server : public Socket, public Settings{
	private:
		std::map<int, Request *>	fdClient;
		int							_socketFd;
		Mime						_mimes;

		AMethods	*defineMethods(std::string method);

	public:
		Server();
		~Server();
		std::string		getMime(std::string path);
		void			response(int fd, Request *request);
};
