/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:07:03 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/06 14:07:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"
#include "utils.hpp"

std::string Log::color[] = {BLUE, MAGENTA, CYAN};
int			Log::index = 0;

void	Log::message(const char *first, ...){
	va_list			vl;
	std::time_t		time = 0;
	const char		*str = first;

	va_start(vl, first);
	std::cerr << GREEN << '[' << getCurrentDateTime(time) << "] Log: " << RESET;
	if (index == 3)
		index = 0;
	std::cerr << ITALI << BOLD << SUBLI << color[index];
	do{
		if (str != NULL){
			std::cerr << ITALI << BOLD << SUBLI << color[index];
			std::cerr << str;
			std::cerr << RESET << " ";
		}
		str = va_arg(vl, const char *);
	}while (str != NULL);
	index++;
	std::cerr << RESET << "\n";
	va_end(vl);
}

