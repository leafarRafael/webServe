/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:45:47 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/29 13:11:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Request.hpp"
#include <list>

class DataRequest{
	protected:
		static std::string	extensionCGI[7];
		std::string			_path_html;
		std::string			_path_cgi;
		std::string			_path_info;
		std::string			_query_string;
		bool				_isCGI;

		std::string			_method;
		std::string			_body;
		std::string			_content_length;
		std::string			_content_type;
		std::string			_http_version;
		std::string			_server_name;


		void			splitURL(std::string url);
		std::string		addQueryString(std::string url);
		std::string		addPathInfo(std::string url);
		void			addPathCGI(std::string url);

		std::string		joinHeaders(std::list<std::string> header);
	
	public:
		DataRequest();
		~DataRequest();
		void	setDateRequest(Request &request);
};