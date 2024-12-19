/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PathLocation.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/17 14:59:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class PathLocation{
	private:
		std::string _pathLocation;

	public:
		void		setPathLocation(std::string pathLocation);
		std::string	getPathLocation();
};