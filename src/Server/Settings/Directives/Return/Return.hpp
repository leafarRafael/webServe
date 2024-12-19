/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Return.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:48 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 13:42:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>


class Return{
	private:
		std::string	_addReturn;
	public:
		void		setReturn(std::string addReturn);
		std::string	getReturn();
};