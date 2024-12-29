/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBody.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:24:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 13:58:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <list>

class DataBody{
	private:
		std::string		_content;

	public:
		void			setContent(std::string &value);
		void			setContentApend(std::string value, std::size_t length);
		std::string		getContent() const;

	public:
		DataBody&operator=(const DataBody & orin);
		DataBody();
		~DataBody(){};
};