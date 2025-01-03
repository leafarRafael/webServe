/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllowMethods.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:27:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 09:52:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <list>
#include "DirectivesBase.hpp"

class AllowMethods : public DirectivesBase{
	private:
		std::list<std::string>	_allowMethods;

	public:
		AllowMethods();
		AllowMethods&operator=(const AllowMethods &origin);
		void					setAllowMethods(std::string allowMethods);
		std::list<std::string>	getAllowMethods();
		bool					isAllowedMethod(std::string method);
};