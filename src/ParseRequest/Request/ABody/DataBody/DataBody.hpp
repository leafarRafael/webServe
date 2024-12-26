/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBody.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:24:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/26 13:39:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <list>

using namespace std;

class DataBody{
	private:
		map<string, list<string> >	_headers;
		string						_content;

	public:
		map<string, list<string> >	getAllHeaders() const;
		void			setNewHeaders(string &key, string &value);
		void			setContent(string &value);
		void			setContentApend(string value, size_t length);
		list<string>	getHeaders(string key) const;
		string			getContent() const;

	public:
		DataBody&operator=(const DataBody & orin);
		DataBody();
		~DataBody(){};
};