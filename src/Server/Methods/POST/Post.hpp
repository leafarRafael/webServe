/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Post.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:22:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/30 17:07:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMethods.hpp"

class Post: public AMethods{
	private:
		void		processFILE();
		void		processCGI();

	public:
		Post();
		~Post();
		HTTP	createHTTP();
};

