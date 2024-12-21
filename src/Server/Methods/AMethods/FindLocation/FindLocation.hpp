/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindLocation.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:41:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 10:54:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "DataLocation.hpp"
#include "Server.hpp"
#include "Request.hpp"

class FindLocation{
	private:
		DataLocation	validIfHaveLocation(std::string path, Server &server);
		std::string		getPrefix(std::string path);
	
	protected:
		DataLocation findLocation(Server &server, Request &request);	
};