/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:00:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/01 19:20:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <stdlib.h>

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie(void)
{
	std::cout << RED << name << RESET << \
		": has perished." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << GREEN << name << RESET << BRAINZZ << std::endl;
}

Zombie	*newZombie(std::string name)
{
	Zombie	*z;

	z = new Zombie(name);
	if (z == nullptr)
		exit(EXIT_FAILURE);
	return (z);
}
