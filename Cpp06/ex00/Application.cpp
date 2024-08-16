/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:52:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/16 17:20:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Application.h"
#include "ScalarConverter.h"
#include <iostream>

Application*	Application::_instance = NULL;

Application::Application(int ac, char **av): _ac(ac), _av(av)
{
	if (_ac != 2)
		throw InvalidNumberArgumentsException();
	_instance = this;
}

Application::~Application(void)
{
	_instance = NULL;
}

Application*	Application::createApplication(int ac, char **av)
{
	if (_instance == NULL)
		_instance = new Application(ac ,av);
	return (_instance);
}

void	Application::run(void)
{
	std::string	input(_av[1]);
	size_t		pos;
	int			flags;

	pos = 0;
	flags = 0;
	if (input == "nanf" || input == "+inff" || input == "-inff")
		flags = FLOAT | LITERAL;
	else if (input == "nan" || input == "+inf" || input == "-inf")
		flags  = DOUBLE | LITERAL;
	else
	{

	}
	ScalarConverter::convert(input, flags);
}

const char*	Application::BadArgumentException::what(void) const throw()
{
	return ("Error: Bad argument.");
}

const char*	Application::InvalidNumberArgumentsException::what(void) const throw()
{
	return ("Error: Invalid number of arguments");
}


