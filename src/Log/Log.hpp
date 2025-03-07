/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:28 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 11:44:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"
#include <iostream>
#include <cstdarg>
#include <ostream>

class Log{
	private:
		static int			index;
		static std::string	color[];
		Log();
		~Log();
	public:
		static void	message(const char *first, ...);
};

