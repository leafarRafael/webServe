/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDefault.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:08:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/20 19:56:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>


class ErrorDefault{
	private:
		static std::map<int, std::string> _error;
		static void initError();
		ErrorDefault(){};
		~ErrorDefault(){};
	public:
		static std::string	getErrorDefault(int errorCode);
		
};