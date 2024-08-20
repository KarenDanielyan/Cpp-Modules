/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:52:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 01:48:02 by kdaniely         ###   ########.fr       */
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
	int			flags;

	flags = 0;
	if (input == "nanf" || input == "+inff" || input == "-inff")
		flags = FLOAT | LITERAL;
	else if (input == "nan" || input == "+inf" || input == "-inf")
		flags  = DOUBLE | LITERAL;
	else
		flags = validate(input);
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

static int	validate(const std::string& input)
{
	int	flags;

	flags = 0;
	if (input.length() == 1 && \
		(std::isprint(input[0]) && !std::isdigit(input[0])))
		return (CHAR);
	for (size_t idx = 0; idx < input.length(); \
		idx = input.find_first_not_of("0123456789", idx))
	{
		switch (input[idx])
		{
			case '-':
			case '+':
				if (flags & SIGNED || input.length() == 1)
					throw Application::BadArgumentException();
				idx ++;
				flags |= SIGNED;
				break ;
			case '.' :
				if (flags & DOUBLE || idx == 0 || !std::isdigit(input[idx - 1]) || \
					!std::isdigit(input[idx + 1]))
					throw Application::BadArgumentException();
				flags |= DOUBLE;
				idx ++;
				break ;
			case 'f' :
				if (idx != input.length() - 1)
					throw Application::BadArgumentException();
				flags |= FLOAT;
				idx ++;
				break ;
			default :
				if (!std::isdigit(input[idx]))
					throw Application::BadArgumentException();
		}
	}
	return (flags | INT);
}
