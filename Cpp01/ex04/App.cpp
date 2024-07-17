/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:45:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 16:00:35 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "App.h"
#include <cstdlib>

App::App(const char *filename, std::string toReplace, \
	std::string replaceWith): in_file_(filename), \
	out_file_((std::string(filename) + ".replace").c_str()),
	to_replace_(toReplace), replace_with_(replaceWith), state_(IDLE)
{
	if (!in_file_.is_open())
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
		switch(state_)
		{
			case IDLE:
				if (std::getline(in_file_, buffer))
					state_ = TEST;
				else
					state_ = EXIT;
				continue ;
			case TEST:
				if (buffer.empty())
				{
					out_file_ << "\n";
					state_ = IDLE;
					continue ;
				}
				loc = buffer.find(to_replace_);
				if (loc == std::string::npos)
					state_ = NOOCUURENCE;
				else
					state_ = FOUNDOCCURENCE;
				continue ;
			case NOOCUURENCE:
				out_file_ << buffer;
				buffer.clear();
				state_ = TEST;
				continue ;
			case FOUNDOCCURENCE:
				out_file_ << buffer.substr(0, loc);
				out_file_ << replace_with_;
				buffer.erase(0, loc + to_replace_.length());
				state_ = TEST;
				continue ;
			case EXIT:
				return ;
		}
	}
}