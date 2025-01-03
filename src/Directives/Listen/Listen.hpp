/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:24:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:04:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>
#include "DirectivesBase.hpp"

class Listen : public DirectivesBase{
	private:
		std::string _ip;
		std::string _port;

		void	addPortIP(std::list<std::string> tokens);
		void	setPort(std::string token);
		void	setIP(std::string token);

	public:
		Listen&operator=(Listen const &origin);
		Listen();

		void		setListen(std::string listen);
		std::string	getIP();
		std::string	getPort();
};