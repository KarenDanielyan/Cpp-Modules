/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Applcation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:14:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/09 18:33:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLCATION_H
# define APPLCATION_H

#include <iostream>

class	Applcation
{
private:
	int					_ac;
	const std::string	_av;

	Applcation();
	Applcation(const Applcation& other);

	Applcation&	operator=(const Applcation& other);

	~Applcation()
	{
		std::cout << "TEST" << std::endl;
	}
public
	static Application&	createApplication(void)
	{
		static Application	App();
		return (App);
	}
};

#endif
