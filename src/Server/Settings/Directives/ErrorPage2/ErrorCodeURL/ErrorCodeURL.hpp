/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorCodeURL.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:21:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/16 11:48:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <string>
#include <algorithm>

class ErrorCodeURL{
	private:
		std::string		_urlErrorPage;
		std::list<int>	_erroCode;

	public:
		void	setURLErrorPage(std::string error_page);
		void	setURLErrorCode(int errorCode);
		void	setURLErrorCode(std::string errorCode);
		std::string	getUrlErrorPage(int errorCode);
};
