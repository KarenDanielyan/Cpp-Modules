/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:59:50 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/18 15:21:52 by kdaniely         ###   ########.fr       */
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
	_instance = NULL;
}

App*	App::createApp(int ac, char **av)
{
	if (ac != 2)
		throw (std::runtime_error("Error: Invalid number of arguments!"));
	if (_instance == NULL)
		_instance = new App(av[1]);
	return (_instance);
}

int	App::_validateLine(std::string const & line) const
{
	if (!Utils::validateDate(line.substr(0, 10)))
		return (BadDate);
	else if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (BadEntry);
	else if (!Utils::validateRate(line.substr(13)))
		return (BadValue);
	return (Success);
}

void	App::run()
{
	std::string	line;
	double		value;
	time_t		time;

	if (std::getline(_file, line))
	{
		if (line != "date | value")
			throw (std::runtime_error("Error: Invalid header!"));
	}
	while (std::getline(_file, line))
	{
		int	exitCode;

		try
		{
			exitCode = this->_validateLine(line);
			switch (exitCode)
			{
				case BadDate:
					throw (std::runtime_error("Error: Bad Input => " + line.substr(0, 10)));
					break ;
				case BadValue:
					throw (std::runtime_error("Error: Excpected a positive integer!"));
					break ;
				case BadEntry:
					throw (std::runtime_error("Error: Invalid entry!"));
					break ;
				case Success:
					time = Utils::convertToEpoch(line.substr(0, 10));
					value = std::atof(line.substr(13).c_str());
					if (value > 1000)
						throw (std::runtime_error("Error: Value too large!"));
					std::cout << line.substr(0, 10) << " => " << value << \
						" = " << _btc.getRate(time, value) << std::endl;
					break ;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	App::destroyApp()
{
	delete _instance;
}

