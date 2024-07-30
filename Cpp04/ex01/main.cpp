/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:18 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 20:25:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.h"
#include "Cat.h"
#include "Dog.h"

int	main(void)
{
	Cat	*megatron;
	Dog	*cupcake;

	megatron = new Cat();
	cupcake = new Dog();

	delete megatron;
	delete cupcake;
	return (0);
}
