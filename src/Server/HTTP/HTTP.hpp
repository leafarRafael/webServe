/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HTTP.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:32:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 14:01:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <map>
#include <string>
#include <ostream>

# include "StatusLine.hpp"
# include "Headers.hpp"
# include "Body.hpp"

class HTTP{
	private:
		StatusLine		_statusLine;
		Headers			_headers;
		Body			_body;

	public:
		StatusLine		getStatusLine() const;
		Headers			getHeaders() const;
		Body			getBody() const;
	
		void		setBody(std::string body);
		std::string	getHTTP() const;

		template<typename T>
		void	setHeaders(std::string headers, T value){
			std::ostringstream ss;
			ss << value;
			_headers.setHeaders(headers, ss.str());
		}

		template<typename T>
		void	setStatusResponse(T statusCode, std::string statusMensage){
			std::ostringstream ss;
			ss << statusCode;
			_statusLine.setStatusCode(ss.str());
			_statusLine.setStatusMensage(statusMensage);
		}
};

std::ostream &operator<<(std::ostream &os, const HTTP &statusLine);