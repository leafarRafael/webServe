/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaxBodySize.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/16 20:00:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class MaxBodySize{
	private:
		void	getFormatValue(std::string maxBodySize);
		void	setValue();
		std::size_t _maxBodySize;
		std::string	_value;
		std::string	_format;

	public:
		MaxBodySize();
		void		setMaxBodySize(std::string maxBodySize);
		std::size_t	getMaxBodySize();
};