/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:42:50 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 16:23:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

#include <iostream>
#include <fstream>

class App
{
	public:
		App(const char *filename, std::string toReplace, \
			std::string replaceWith);
		void	run(void);
		enum	State_e
		{
			IDLE,
			TEST,
			NOOCUURENCE,
			FOUNDOCCURENCE,
			EXIT
		};
	private:
		std::ifstream	in_file;
		std::ofstream	out_file;
		std::string		to_replace;
		std::string		replace_with;
		State_e			state;
};

#endif
