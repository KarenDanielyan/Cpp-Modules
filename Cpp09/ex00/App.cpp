/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:59:50 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/01 18:46:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "App.hpp"
#include <iostream>

App*	App::_instance = NULL;

App::App() {}

App::App(const App&) {}

App&	App::operator=(const App&)
{
	return (*this);
}

App::App(const char *file) : _file(file)
{
	if (!_file.is_open())
		throw (std::runtime_error("Error: Cannot open the input file!"));
}

App::~App()
{
	_file.close();
	delete [] _instance;
}

App*	App::createApp(int ac, char **av)
{
	if (ac != 2)
		throw (std::runtime_error("Error: Invalid number of arguments!"));
	if (_instance == NULL)
		_instance = new App(av[1]);
	return (_instance);
}

void	App::run()
{
	std::string	line;
	double		value;

	while (std::getline(_file, line))
	{
		try
		{
			value = _btc.getRate(line);
			std::cout << value << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

