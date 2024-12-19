/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:10:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/18 19:43:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "DataLocation.hpp"
#include <list>

#include "ErrorPage2.hpp"
#include "Listen2.hpp"
#include "ServerName.hpp"
#include "MaxBodySize.hpp"
#include "Root.hpp"
#include "Index.hpp"

typedef struct pointer
{
	std::string	input;
	void (DataLocation::*function)(std::string);

}	t_pointer;

class Location2{
	private:
		static	t_pointer				direc[8];
		std::list<DataLocation>			_locations;


		void	normalizeLocation(std::list<std::string> &tokens);
		void	addLocationToData(std::list<std::string> &tokens, DataLocation &data);
		void	setDirective(std::string directive, DataLocation &data);

	public:
		void			setLocation(std::string location);
		DataLocation	getLocation(std::string	path);
		
};

