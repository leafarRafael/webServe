/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerName.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:23:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class ServerName : public DirectivesBase{
	private:
		std::string _serverName;

	public:
		ServerName();
		ServerName&operator=(ServerName const &origin);
		void		setServerName(std::string serverName);
		std::string	getServerName();
};