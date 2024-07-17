/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:48:02 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/17 16:00:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "App.h"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: <file> <string-to-replace> <string-to-replace-with>" << std::endl;
		return (1);
	}
	App	app(av[1], av[2], av[3]);
	app.run();
	return (0);
}