/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:52:39 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/01 16:17:46 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <string>
# include <map>
# include <ctime>

class	BitcoinExchange
{
private:
	static const char*			_file;
	std::map<time_t, double>	_rates;
	
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	time_t	_convertToEpoch(std::string const & date) const;

	void	_checkForHeader(std::string const & line) const;
	bool	_validateLine(std::string const & line) const;
public:
	BitcoinExchange();
	~BitcoinExchange();

	double	getRate(std::string const & entry) const;
};

#endif