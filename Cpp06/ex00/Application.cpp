/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:52:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/15 22:03:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Application.h"
#include <iostream>

Application*	Application::_instance = NULL;

Application::Application(int ac, char **av): _ac(ac), _av(av)
{
	if (_ac != 2)
		throw InvalidArgumentsException();
	_instance = this;
}

Application::~Application(void)
{
	_instance = NULL;
}

Application*	Application::createApplication(int ac, char **av)
{
	Application*	app;

	if (_instance == NULL)
		app = new Application(ac ,av);
	return (_instance);
}

void	Application::run(void)
{
	std::string	input = _av[1];
	int			type;
	size_t		loc;

	(void)flags;
	loc = input.find_first_not_of("1234567890");
	if (loc != std::string::npos)
	{
		if (loc == input.length() - 1 && input[loc] == 'f')
		{
			std::cout << "It seems that it's an floating point number" << std::endl;
		}
		else
			std::cout << "It's not a floating point number" << std::endl;
	}
}

const char*	Application::InvalidArgumentsException::what(void) const throw()
{
	return ("Error: Invalid number of arguments");
}


