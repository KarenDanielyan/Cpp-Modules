/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 16:54:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal(void): type("Bob")
{
	std::cout << GREEN << ANIMAL_DFLT \
		<< RESET << std::endl;
}

Animal::Animal(const std::string type): type(type)
{
	std::cout << GREEN << ANIMAL_PARAM \
		<< RESET << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << GREEN << ANIMAL_COPY \
		<< RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << RED << ANIMAL_DESTR \
		<< RESET << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << GREEN << ANIMAL_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

void	Animal::makeSound(void)
{
	std::cout << ANIMAL_SOUND << std::endl;
}
