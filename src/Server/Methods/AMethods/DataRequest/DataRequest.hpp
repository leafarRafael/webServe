/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:45:47 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/07 12:32:38 by rbutzke          ###   ########.fr       */
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
		int					_errorRequest;
		bool				_isAllowMethodInPathTraslated;
		bool				_existeTraslated;
		std::size_t			_maxBodyTraslated;
		std::size_t			_requestContentLenght;

		std::string			_method;
		std::string			_body;
		std::string			_content_length;
		std::string			_content_type;
		std::string			_http_version;

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