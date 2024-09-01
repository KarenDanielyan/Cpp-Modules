/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:56:02 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/01 18:33:27 by kdaniely         ###   ########.fr       */
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
		time = _convertToEpoch(line.substr(0, 10));
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

double	BitcoinExchange::getRate(std::string const & entry) const
{
	std::map<time_t, double>::const_iterator	it;
	time_t	time;
	double	value;

	if (!_validateLine(entry))
		throw std::runtime_error("Error: Invalid entry!");
	time = _convertToEpoch(entry.substr(0, 10));
	for (it = _rates.begin(); it->first <= time && it != _rates.end(); it++)
			;
	value = std::atof(entry.substr(11).c_str());
	if (value > 1000)
		throw std::runtime_error("Error: Invalid Entry!");
	if (it->first == time)
		return (it->second * value);
	else
		return ((--it)->second * value);
}

time_t	BitcoinExchange::_convertToEpoch(std::string const & date) const
{
	struct tm	time = {0,0,0,0,0,0,0,0,0,0,0};

	time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
	time.tm_mon = std::atoi(date.substr(5, 2).c_str()) - 1;
	time.tm_mday = std::atoi(date.substr(8, 2).c_str());
	return (mktime(&time));
}

void	BitcoinExchange::_checkForHeader(std::string const & line) const
{
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: Invalid header!");
}

static bool _validateDate(std::string const & date);
static bool _validateRate(std::string const & rate);

bool	BitcoinExchange::_validateLine(std::string const & line) const
{
	return (_validateDate(line.substr(0, 10)) && _validateRate(line.substr(11)));
}

static bool _validateDate(std::string const & date)
{
	int	year;
	int	month;
	int	day;

	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1970 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

static bool	_validateRate(std::string const & rate)
{
	bool	dot = false;

	if (rate.empty())
		return (false);
	for (size_t i = 0; i < rate.length(); i++)
	{
		if (rate[i] == '.' && !dot)
		{
			dot = true;
			continue;
		}
		if (!std::isdigit(rate[i]))
			return (false);
	}
	return (true);
}
