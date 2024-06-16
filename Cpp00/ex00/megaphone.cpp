/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:08:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/15 01:53:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	my_toupper(char *str);

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (*(++av))
			my_toupper(*av);
	}
	std::cout << std::endl;
	return (0);
}

void	my_toupper(char *str)
{
	while (*str)
	{
		std::cout << (char)std::toupper(*str);
		str++;
	}
}
