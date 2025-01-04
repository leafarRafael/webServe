/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignalHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:24:32 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/04 18:06:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <csignal>

class SignalHandler{
	private:
		static bool _break;
		SignalHandler(){};
		~SignalHandler(){};
	public:
		static void	ignoreSigPipe();
		static void	signalHandler(int signal);
		static bool	breakLooping();
		static void	setBreakLooping(bool value);		
};