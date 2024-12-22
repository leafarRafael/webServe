/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Return.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:48 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:19:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class Return : public DirectivesBase{
	private:
		std::string	_addReturn;

	public:
		Return();
		Return&operator=(Return const &origin);
		void		setReturn(std::string addReturn);
		std::string	getReturn();
};