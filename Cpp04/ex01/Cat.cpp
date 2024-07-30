/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:23:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 20:02:39 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat(void): Animal("Cat")
{
	_brain = new Brain();
	std::cout << GREEN << CAT_DFLT \
		<< RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << GREEN << CAT_COPY \
		<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	this->type = other.type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	std::cout << GREEN << CAT_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << RED << CAT_DESTR \
		<< RESET << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << BLUE << CAT_SOUND << RESET << std::endl;
}
