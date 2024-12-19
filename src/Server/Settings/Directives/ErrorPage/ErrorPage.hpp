/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorPage.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:35:45 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/19 17:04:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>
#include <algorithm>
#include "ErrorCodeURL.hpp"

class ErrorPage{
	private:
		std::list<ErrorCodeURL> _error;
		void	findSetErrorCode(std::list<std::string> &tokens, ErrorCodeURL &errorContent);
		void	findSetErrorPage(std::list<std::string> &tokens, ErrorCodeURL &errorContent);

	public:
		void		setErrorPage(std::string &error_page);
		std::string	getErrorPage(int errorCode);
};