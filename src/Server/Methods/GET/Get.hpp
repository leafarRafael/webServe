/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:22:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/24 13:38:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMethods.hpp"

class Get: public AMethods{
	private:
		std::string	validHeaders(Request &request);

	public:
		Get();
		~Get();
		HTTP	createHTTP(Server &server, Request &request);
};

