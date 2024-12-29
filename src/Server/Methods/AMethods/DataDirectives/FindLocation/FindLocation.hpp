/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindLocation.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:41:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/27 18:21:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "DataLocation.hpp"
#include "Server.hpp"
#include "Request.hpp"

class FindLocation{
	private:
		static DataLocation	validIfHaveLocation(std::string path, Server &server);
		
		static std::string	getPrefix(std::string path);
		FindLocation(){};
		~FindLocation(){};
	
	public:
		static DataLocation	findLocation(Server &server, Request &request);
		static DataLocation	findLocation(Server &server, std::string path);	
};