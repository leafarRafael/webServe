/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReasonPhrase.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:32:29 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 12:46:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <string>
#include <map>

class ReasonPhrase{
	private:
		static std::map<int, std::string>	_reasonPhrase;
		ReasonPhrase();
		~ReasonPhrase();
		static void	initReasonPhrase();
	public:
		static std::string	getPhrase(int status);
};