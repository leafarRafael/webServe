/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndex.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:19:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 13:21:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>


class AutoIndex{
	private:
		std::string	_autoIndex;

	public:
		void		setAutoIndex(std::string autoIndex);
		std::string	getAutoIndex();
		bool		getAutoIndexBool();
};