/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:49 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/07 16:26:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <netinet/in.h>
# include <inttypes.h>

#define BACK_LOG_LISTEN 256


class Socket {
	private:
		int				_socketFd;
		sockaddr_in		_addr;
		virtual void	initSocket();
		virtual void	setSocketReusable();
		virtual void	setPortReusable();
		virtual void	setAddr(const char *port, const char *ip);
		virtual void	setAddrToSocket();
		virtual void	putSocketListeningLimit();

	public:
		Socket();
		~Socket();
		int				getSocketFd(void) const;
		void			setSocketFd(const int socketFd);
		virtual void	initTCP(const char *port, const char *ip);
};
