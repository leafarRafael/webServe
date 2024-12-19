/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:24:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/16 18:38:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>


class Listen2{
	private:
		std::string _ip;
		std::string _port;

		void	addPortIP(std::list<std::string> tokens);
		void	setPort(std::string token);
		void	setIP(std::string token);

	public:
		Listen2();

		void		setListen(std::string listen);
		std::string	getIP();
		std::string	getPort();
};