/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/29 16:03:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal(void): type("Bob")
{
	std::cout << GREEN << "[ Animal default constructor called ]" \
		<< RESET << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << GREEN << "[ Animal copy-constructor called ]" \
		<< RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << RED << "[ Animal destructor called ]" \
		<< RESET << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << GREEN << "[ Animal assignment operator called ]" \
		<< RESET << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << "* GENERIC ANIMAL VOICES *" << std::endl;
}
