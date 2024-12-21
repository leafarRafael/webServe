/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataLocation.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:11:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/21 10:21:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Root.hpp"
#include "Index.hpp"
#include "ErrorPage.hpp"
#include "MaxBodySize.hpp"
#include "AutoIndex.hpp"
#include "AllowMethods.hpp"
#include "Return.hpp"
#include "PathLocation.hpp"

class DataLocation{
	private:
		int				_instances;
		PathLocation	_pathLocation;
		Root			_root;
		Index			_index;
		ErrorPage		_errorPage;
		MaxBodySize		_maxBodySize;
		AutoIndex		_autoIndex;
		AllowMethods	_allowMethods;
		Return			_returnIndex;
		
	public:
		DataLocation():_instances(0){}
		void setPathLocation(std::string pathLocation);
		void setRoot(std::string root);
		void setIndex(std::string index);
		void setErrorPage(std::string errorPage);
		void setMaxBodySize(std::string maxBodySize);
		void setAutoIndex(std::string autoIndex);
		void setAllowMethods(std::string allowMethods);
		void setReturn(std::string returnIndex);


		std::string getPathLocation();
		std::string getRoot();
		std::string getIndex();
		std::string	getErrorPage(int errorCode);
		std::size_t	getMaxBodySize();
		bool		getAutoIndexBool();
		bool		isAllowedMethod(std::string method);
		std::string getReturn();
		bool			empty();

};


