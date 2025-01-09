/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:37:59 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/09 17:19:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <map>
# include "Socket.hpp"
# include "Settings.hpp"
# include "HTTP.hpp"

class AMethods;
class Request;
class Directive;

class Server : public Socket, public Settings{
	private:
		AMethods	*defineMethods(std::string method);

	public:
		Server();
		virtual ~Server();
		void		response(int fd, Request *request);
};
