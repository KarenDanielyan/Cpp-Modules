/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:18 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 00:14:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.h"
#include "Cat.h"
#include "Dog.h"

int	main(void)
{
	Cat				kitten;
	Dog				cupcake;
	Animal*			p_cat = &kitten;
	Animal&			r_dog = cupcake;
	WrongAnimal*	p_wrong = new WrongCat();

	std::cout << "- - - - - - - - - -" << std::endl;
	std::cout << "If classes are implemented correctly " << \
				"we should see the same result." << std::endl;
	std::cout << "The Cat: ";
	kitten.makeSound();
	std::cout << "Pointer Cat: ";
	p_cat->makeSound();
	std::cout << "The Dog: ";
	cupcake.makeSound();
	std::cout << "Reference Dog: ";
	r_dog.makeSound();
	std::cout << "Now let's see what happens when " << \
			"the implementations are wrong." << std::endl;
	std::cout << "Wrong Cat: ";
	p_wrong->makeSound();
	std::cout << "- - - - - - - - - -" << std::endl;
	return (0);
}