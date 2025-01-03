/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaxBodySize.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 10:16:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "DirectivesBase.hpp"

class MaxBodySize : public DirectivesBase{
	private:
		void		getFormatValue(std::string maxBodySize);
		void		setValue();
		std::size_t _maxBodySize;
		std::string	_value;
		std::string	_format;

	public:
		MaxBodySize&operator=(MaxBodySize const &origin);
		MaxBodySize();
		void		setMaxBodySize(std::string maxBodySize);
		std::size_t	getMaxBodySize();
};