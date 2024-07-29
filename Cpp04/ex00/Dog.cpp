/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:46:38 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 00:02:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << GREEN << "[ Dog default constructor called ]" \
		<< RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GREEN << "[ Dog copy constructor called ]" \
		<< RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << RED << "[ Dog destructor called ]" \
		<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	this->type = other.type;
	std::cout << GREEN << "[ Dog copy assignment operator called ]" \
		<< RESET << std::endl;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << CYAN << "* BARK *" << RESET << std::endl;
}