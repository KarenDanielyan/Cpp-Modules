/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:52:39 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/01 03:13:09 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <algorithm>
# include <map>

class	BitcoinExchange
{
private:
	static const char*	_file;
	std::map<size_t, double>	_rates;
	
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	size_t	_convertToEpoch(std::string const & date) const;
public:
	BitcoinExchange();
	~BitcoinExchange();

	double	getRate(size_t time, double amount) const;
};

#endif