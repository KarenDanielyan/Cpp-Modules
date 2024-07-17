/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:45:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 16:24:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "App.h"
#include <cstdlib>

App::App(const char *filename, std::string toReplace, \
	std::string replaceWith): in_file(filename), \
	out_file((std::string(filename) + ".replace").c_str()),
	to_replace(toReplace), replace_with(replaceWith), state(IDLE)
{
	if (!in_file.is_open())
	{
		std::cout << "Error: File does not exist." << std::endl;
		exit(1);
	}
}

void	App::run()
{
	std::string	buffer;
	size_t		loc;

	while (true)
	{
		switch(state)
		{
			case IDLE:
				if (std::getline(in_file, buffer))
					state = TEST;
				else
					state = EXIT;
				continue ;
			case TEST:
				if (buffer.empty())
				{
					out_file << "\n";
					state = IDLE;
					continue ;
				}
				loc = buffer.find(to_replace);
				if (loc == std::string::npos)
					state = NOOCUURENCE;
				else
					state = FOUNDOCCURENCE;
				continue ;
			case NOOCUURENCE:
				out_file << buffer;
				buffer.clear();
				state = TEST;
				continue ;
			case FOUNDOCCURENCE:
				out_file << buffer.substr(0, loc);
				out_file << replace_with;
				buffer.erase(0, loc + to_replace.length());
				state = TEST;
				continue ;
			case EXIT:
				return ;
		}
	}
}