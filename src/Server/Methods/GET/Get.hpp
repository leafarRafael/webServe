/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:22:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 11:34:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMethods.hpp"

class Get: public AMethods{
	public:
		Get();
		~Get();
		HTTP	createHTTP(Server &server, Request &request);
};

