/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:09:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/01 19:21:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
	Zombie karl("karl");
	Zombie *cone;

	cone = newZombie("Cone");
	karl.announce();
	cone->announce();
	randomChump("Cabron");
	delete cone;
	return (0);
}