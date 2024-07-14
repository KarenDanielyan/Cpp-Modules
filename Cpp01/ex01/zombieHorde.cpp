/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:42:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/14 15:59:41kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <cstdlib>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	(void)name;
	horde = new Zombie[N];
	if (horde == NULL)
		exit(1);
	for (int i = 0; i < N; i ++)
		horde[i] = Zombie(name);
	return (horde);
}