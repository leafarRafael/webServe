/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:33:31 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/01 15:21:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Listen.hpp"
#include "ErrorPage.hpp"
#include "ServerName.hpp"
#include "MaxBodySize.hpp"
#include "Root.hpp"
#include "Index.hpp"
#include "AllowMethods.hpp"
#include "Return.hpp"

class DataServer{
	private:
		Root					_root;
		Index					_index;
		ErrorPage				_errorPage;
		MaxBodySize				_maxBodySize;
		Listen					_listen;
		ServerName				_serverName;
		AllowMethods			_allowMethods;
		Return					_directiveReturn;

	public:
		DataServer();
		DataServer&operator=(DataServer const &origin);
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

		void		setReturn(std::string index);
		std::string	getReturnAddr();
		int			getReturnStatus();

		MaxBodySize		getMaxBodySizeOBJ();
		Root			getRootOBJ();
		Index			getIndexOBJ();
		ErrorPage		getErrorPageOBJ();
		ServerName		getServerNameOBJ();
		AllowMethods	getAllowMethodsOBJ();
		Return			getReturnOBJ();

};