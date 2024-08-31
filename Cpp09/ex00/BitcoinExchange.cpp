/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:56:02 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/01 03:13:29 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

const char*	BitcoinExchange::_file = "private/data.csv";

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file(_file);
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file!");
	for (int lineNum = 0; std::getline(file, line); lineNum++)
	{
		if (lineNum == 0)
			continue;
		size_t		time = _convertToEpoch(line.substr(0, 10));
		double		rate = std::atof(line.substr(11).c_str());
		_rates[time] = rate;
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

size_t	BitcoinExchange::_convertToEpoch(std::string const & date) const
{
	(void)date;
	return (0);
}