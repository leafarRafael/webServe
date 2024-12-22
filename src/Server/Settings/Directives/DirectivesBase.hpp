/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectivesBase.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:42:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/12/22 09:55:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class DirectivesBase{
	protected:
		int	_instances;

		~DirectivesBase();
		DirectivesBase();
		DirectivesBase&operator=(DirectivesBase const &origin);
	public:
		bool	empty();
};