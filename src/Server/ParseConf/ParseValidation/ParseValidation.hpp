/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseValidation.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:40:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/18 17:47:46 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ParseValidation{
	protected:
		void	validFileExtension(std::string file);
		void	validCurlyBraces(std::string &buffer);
		void	validDirectivesServer(std::string &server);
		void	validDirectivesLocation(std::string &location);
};