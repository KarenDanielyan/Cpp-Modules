/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:18 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 14:03:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.h"
#include "Dog.h"

void	atexit()
{
	system("leaks ex02");
}

int	main(void)
{
	AAnimal*	animals[100];

	std::atexit(&atexit);
	for (int i = 0; i < 50; i++)
		animals[i] = new Cat();
	for (int i = 50; i < 100; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 100; i ++)
		delete animals[i];
	return (0);
}
