/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:33:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 17:03:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Listen.hpp"
#include "ErrorPage.hpp"
#include "ServerName.hpp"
#include "MaxBodySize.hpp"
#include "Root.hpp"
#include "Index.hpp"

class DataServer{
	private:
		Listen					_listen;
		ErrorPage				_errorPage;
		ServerName				_serverName;
		MaxBodySize				_maxBodySize;
		Root					_root;
		Index					_index;

	public:
		//Listen Methods
		void			setListen(std::string listen);
		std::string		getIP();
		std::string		getPort();

		//ErrorPage Methods
		void			setErrorPage(std::string error_page);
		std::string		getErrorPage(int statusCode);

		//ServerName Methods
		void		setServerName(std::string serverName);
		std::string	getServerName();

		//MaxBody Methods
		void		setMaxBodySize(std::string maxBodySize);
		std::size_t	getMaxBodySize();

		//Root Methods
		void		setRoot(std::string root);
		std::string	getRoot();

		//Index Methods
		void		setIndex(std::string index);
		std::string	getIndex();
		
};