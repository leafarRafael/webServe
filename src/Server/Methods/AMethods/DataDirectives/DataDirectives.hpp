/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataDirectives.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:43:56 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/05 19:08:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "DataServer.hpp"
#include "Request.hpp"

class DataDirectives{
	protected:
		Root			_root;
		Index			_index;
		ErrorPage		_errorPage;
		MaxBodySize		_maxBodySize;
		AutoIndex		_autoIndex;
		AllowMethods	_allowMethods;
		Return			_returnIndex;
		void			addGlobalDirectives(DataServer dataServer);
		void			addLocationDirectives(DataLocation dataLocation);
		DataLocation	findDataLocation(Server &server, Request &request);

	public:
		void	selectDirectives(Server &server, Request &request);
};