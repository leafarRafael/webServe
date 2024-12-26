/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:19:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 11:52:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CGI.hpp"

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstdlib>

std::string	CGI::commonGatewayInterface(Server &server, Request &request){
	std::cout << server.getIP() << request.getHost() << "\n";
	
	int				_pipe[2];
	pid_t			_pid;
	extern char **__environ;
	pipe(_pipe);

	_pid = fork();
	if (_pid == -1){
		std::cout << "Deu MERDA\n";	
	}
	if (_pid == 0){
		setenv((char*)"QUERY_STRING", (char*)"VAIGARAIO", 1);
		setenv((char*)"FULANA", (char*)"VAI GARAIO Novamente", 1);
		setenv((char*)"GATO3.0", (char*)"vish", 1);
		close (_pipe[0]);
		dup2(_pipe[1], STDOUT_FILENO);
		close (_pipe[1]);
		char* const args[] = {
		(char*)"/usr/bin/python3",
		(char*)"/home/rafael/1.py",
		NULL};
		execve(args[0], args, __environ);
	}else{
		int status;
        waitpid(_pid, &status, 0);
		close(_pipe[1]);
		char buf[1000];
		read(_pipe[0], buf, 1000-1);
		close(_pipe[0]);
		buf[200] = '\0';
		std::cout << buf;
	}
	return std::string();
}

