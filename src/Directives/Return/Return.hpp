/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Return.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:48 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:24:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class Return : public DirectivesBase{
	private:
		int			_returnStatus;
		std::string	_addrReturn;

	public:
		Return();
		Return&operator=(Return const &origin);
		void		setReturn(std::string addReturn);
		std::string	getReturnAddr();
		int			getReturnStatus();
};