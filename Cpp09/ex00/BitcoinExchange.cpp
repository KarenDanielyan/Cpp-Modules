/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:56:02 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/02 16:03:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

const char*	BitcoinExchange::_file = "./private/data.csv";

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file(_file);
	std::string		line;
	time_t			time;
	double			rate;

	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file!");
	for (int lineNum = 0; std::getline(file, line); lineNum++)
	{
		if (lineNum == 0)
		{
			_checkForHeader(line);
			continue ;
		}
		else if (!_validateLine(line))
			throw std::runtime_error("Error: Corrupted data!");
		time = Utils::convertToEpoch(line.substr(0, 10));
		rate = std::atof(line.substr(11).c_str());
		_rates.insert(std::pair<time_t, double>(time, rate));
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return (*this);
}

double	BitcoinExchange::getRate(time_t time, double value) const
{
	std::map<time_t, double>::const_iterator	it;

	for (it = _rates.begin(); it->first <= time && it != _rates.end(); it++)
			;
	if (it->first == time)
		return (it->second * value);
	else
		return ((--it)->second * value);
}

void	BitcoinExchange::_checkForHeader(std::string const & line) const
{
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: Invalid header!");
}

bool	BitcoinExchange::_validateLine(std::string const & line) const
{
	return (Utils::validateDate(line.substr(0, 10)) && Utils::validateRate(line.substr(11)));
}
