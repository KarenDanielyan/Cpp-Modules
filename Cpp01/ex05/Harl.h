/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:53:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 21:53:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define RESET "\033[0m"


class Harl
{
	private:
		typedef void (Harl::*HarlFunc)(void);

		struct Map
		{
			std::string level;
			Harl::HarlFunc	action;
		};

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		Map		actions[4];
	public:
		Harl(void);
		void	complain(std::string level);
};

#endif
