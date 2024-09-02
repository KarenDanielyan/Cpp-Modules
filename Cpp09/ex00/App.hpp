/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:58:46 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/02 16:20:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_HPP
# define APP_HPP

# include "BitcoinExchange.hpp"
# include <fstream>
# include <iostream>
# include <string>

class App
{
private:
	BitcoinExchange	_btc;
	std::ifstream	_file;

	static App*			_instance;

	App(void);
	App(const char *file);
	App(const App& other);

	App&	operator=(const App& other);

	~App(void);

	int	_validateLine(std::string const & line) const;
	
	enum	_Error_Code
	{
		BadDate = 1,
		BadValue = 2,
		BadEntry = 3,
		Success = 0
	};
public:
	static App*	createApp(int ac, char **av);
	static void	destroyApp();

	void	run(void);
};

#endif