/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:45:24 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/02 16:10:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool Utils::validateDate(std::string const & date)
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

bool	Utils::validateRate(std::string const & rate)
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

time_t	Utils::convertToEpoch(std::string const & date)
{
	struct tm	time = {0,0,0,0,0,0,0,0,0,0,0};

	time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
	time.tm_mon = std::atoi(date.substr(5, 2).c_str()) - 1;
	time.tm_mday = std::atoi(date.substr(8, 2).c_str());
	return (mktime(&time));
}
