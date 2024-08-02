/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:18 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/02 16:35:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.h"
#include "Dog.h"

int	main(void)
{
	AAnimal*	animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Cat();
	for (int i = 50; i < 100; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 100; i ++)
		delete animals[i];
	return (0);
}
