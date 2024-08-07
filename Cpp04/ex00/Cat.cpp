/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:23:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/29 23:56:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat(void): Animal("Cat")
{
	std::cout << GREEN << "[ Cat default constructor called ]" \
		<< RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << GREEN << "[ Cat copy constructor called ]" \
		<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	this->type = other.type;
	std::cout << GREEN << "[ Cat copy assignment operator called ]" \
		<< RESET << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << RED << "[ Cat destructor called ]" \
		<< RESET << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << BLUE << "* MEOW *" << RESET << std::endl;
}