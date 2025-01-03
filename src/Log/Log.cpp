/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:07:03 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 10:50:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"
#include "utils.hpp"

void	Log::message(const char *first, ...){
	va_list			vl;
	std::time_t		time = 0;
	const char		*str = first;

	va_start(vl, first);
	std::cerr << GREEN << '[' << getCurrentDateTime(time) << "] Log: " << RESET;
	do{
		if (str != NULL)
			std::cerr << str;
		str = va_arg(vl, const char *);
		std::cerr << RESET;	
	}while (str != NULL);
	std::cerr << RESET << "\n";
	va_end(vl);
}
