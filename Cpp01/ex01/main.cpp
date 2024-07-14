/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:09:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/14 15:56:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
	int		N;
	Zombie	*horde;

	N = 5;
	horde = zombieHorde(N, "John Doe");
	for(int i = 0; i < N; i ++)
		horde[i].announce();
	delete[] horde;
	return (0);
}