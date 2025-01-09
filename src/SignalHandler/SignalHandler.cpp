/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignalHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:43 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/09 17:19:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SignalHandler.hpp"
#include <cstdlib>

bool SignalHandler::_break = false;

bool SignalHandler::breakLooping(){
	return _break;
}

void SignalHandler::setBreakLooping(bool value){
	_break = value;
}

void SignalHandler::ignoreSigPipe() {
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGPIPE, &sa, NULL);
}

void SignalHandler::signalHandler(int signal) {
	(void)signal;
	_break = true;
}

void SignalHandler::restoreSignal() {
	struct sigaction sa;

	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	for (int sig = 1; sig < NSIG; ++sig)
		sigaction(sig, &sa, NULL);
}


void	SignalHandler::configSignal(){
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGPIPE, &sa, NULL);
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
}