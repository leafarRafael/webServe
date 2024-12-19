/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllowMethods.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:27:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 15:21:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <list>


class AllowMethods{
	private:
		std::list<std::string> _allowMethods;

	public:
		void					setAllowMethods(std::string allowMethods);
		std::list<std::string>	getAllowMethods();
		bool					isAllowedMethod(std::string method);
};