/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PathLocation.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:17:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class PathLocation : public DirectivesBase{
	private:
		std::string _pathLocation;

	public:
		PathLocation();
		PathLocation&operator=(PathLocation const &origin);
		void		setPathLocation(std::string pathLocation);
		std::string	getPathLocation();
};