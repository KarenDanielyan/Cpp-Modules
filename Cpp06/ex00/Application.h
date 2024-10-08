/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:45:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 01:14:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_H
# define APPLICATION_H

#include <cstdlib>
#include <exception>

enum	ConvertOptions_e
{
	CHAR	= (1 << 0),
	INT		= (1 << 1),
	FLOAT	= (1 << 2),
	DOUBLE	= (1 << 3),
	LITERAL	= (1 << 4),
	SIGNED	= (1 << 5)
};

class	Application
{
private:
	int					_ac;
	char**				_av;
	static Application*	_instance;

	Application&	operator=(const Application& other);

	Application(void);
	Application(int ac, char **av);
	Application(const Application& other);

public:
	static Application*	createApplication(int ac, char **av);
	void				run(void);
	~Application(void);

	class	InvalidNumberArgumentsException: public std::exception
	{
		public:
			const char*	what(void) const throw();
	};
	class	BadArgumentException: public std::exception
	{
		public:
			const char*	what(void) const throw();
	};
};

#endif
