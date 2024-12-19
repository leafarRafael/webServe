/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseTokens.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/18 17:50:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <list>


struct blockServer{
	std::string				_serverScope;
	std::list<std::string>	_locationsScope;
};

class ParseTokens{
	private:
		void	addBlockLocation(blockServer &server);

	protected:
		std::list<blockServer>		_serverBlock;
		void	addBlockServer(std::string &buffer);
	
};