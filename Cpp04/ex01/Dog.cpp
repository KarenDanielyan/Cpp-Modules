/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:46:38 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 20:04:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	_brain = new Brain();
	std::cout << GREEN << DOG_DFLT \
		<< RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << GREEN << DOG_COPY \
		<< RESET << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << RED << DOG_DESTR \
		<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	this->type = other.type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	std::cout << GREEN << DOG_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << CYAN << DOG_SOUND << RESET << std::endl;
}
