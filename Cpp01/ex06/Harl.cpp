/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:00:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 23:58:04 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>

Harl::Harl()
{
	actions[0].level = "DEBUG";
	actions[0].action = &Harl::debug;
	actions[1].level = "INFO";
	actions[1].action = &Harl::info;
	actions[2].level = "WARNING";
	actions[2].action = &Harl::warning;
	actions[3].level = "ERROR";
	actions[3].action = &Harl::error;
}

void	Harl::debug()
{
	std::cout << BLUE << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
	<< std::endl;
}

void	Harl::info()
{
	std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << std::endl;

}

void	Harl::warning()
{
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." \
	<< std::endl;
}

void	Harl::error()
{
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! \
I want to speak to the manager now." << std::endl;
}

int		Harl::translate(std::string &level)
{
	for (int i = 0; i < 4; i ++)
	{
		if (level == actions[i].level)
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	int	l;
	l = translate(level);
	if (l > 0)
		(this->*actions[l].action)();
	std::cout << "[ Probably complaining about insignificant problems. ]" \
			<< std::endl;
}

void	Harl::filter(std::string level)
{
	int	minLevel;

	minLevel = translate(level);
	switch (minLevel)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break ;
		case 1:
			info();
			warning();
			error();
			break ;
		case 2:
			warning();
			error();
			break ;
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems. ]" \
				<< std::endl;
			break ;
	}
}
