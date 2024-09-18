/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:25:39 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/18 16:35:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
	else
	{
		try
		{
			RPN	rpn(av[1]);
			rpn.calculate();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}