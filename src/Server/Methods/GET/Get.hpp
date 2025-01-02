/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:22:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/31 11:46:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMethods.hpp"

class Get: public AMethods{
	private:
		void		processFILE();
		void		processCGI();	

	public:
		Get();
		~Get();
		HTTP	createHTTP();
};

