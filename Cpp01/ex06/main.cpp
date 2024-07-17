/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:02:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 23:57:42 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.h"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 2)
		harl.filter(av[1]);
	else
	{
		std::cout << "[ Probably complaining about insignificant problems. ]" \
			<< std::endl;
	}
	return (0);
}