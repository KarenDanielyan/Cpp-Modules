/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:52:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/13 20:30:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Application.h"

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

void	Application::run(void) {}

const char*	Application::InvalidArgumentsException::what(void) const throw()
{
	return ("Error: Invalid number of arguments");
}


