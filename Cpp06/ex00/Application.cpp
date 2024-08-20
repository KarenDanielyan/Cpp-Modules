/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:52:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/20 17:42:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Application.h"
#include "ScalarConverter.h"
#include <iostream>

static int	validate(const std::string& input);

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
		flags = validate(input);
	ScalarConverter::convert(input, flags);
}

static int	validate(const std::string& input)
{
	size_t	idx;
	int		flags;

	idx = 0;
	flags = 0;
	if (input[0] == '-' || input[0] == '+')
		idx ++;
	while (idx != std::string::npos)
	{
		switch(input[idx])
		{
			case 'f':
				if (idx != input.length() - 1)
					throw Application::BadArgumentException();
				else
					flags |= FLOAT;
				break ;
			case '.':
				if (flags & DOUBLE || !std::isdigit(input[idx + 1]))
					throw Application::BadArgumentException();
				else
					flags |= DOUBLE;
				break ;
			default :
				if ((std::isalpha(input[idx]) && input.length() != 1) || \
					)
					throw Application::BadArgumentException();
				else
					flags |= CHAR;
				break ;
		}
		if (idx != std::string::npos)
			idx ++;
		idx = input.find_first_not_of("0123456789", idx);
	}
	return (flags);
}

const char*	Application::BadArgumentException::what(void) const throw()
{
	return ("Error: Bad argument.");
}

const char*	Application::InvalidNumberArgumentsException::what(void) const throw()
{
	return ("Error: Invalid number of arguments");
}


