/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndex.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:19:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 09:57:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class AutoIndex : public DirectivesBase{
	private:
		std::string	_autoIndex;

	public:
		AutoIndex();
		AutoIndex&operator=(AutoIndex const &origin);
		void		setAutoIndex(std::string autoIndex);
		std::string	getAutoIndex();
		bool		getAutoIndexBool();
};