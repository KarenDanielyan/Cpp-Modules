/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 00:11:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(void): type("Bob")
{
	std::cout << GREEN << "[ WrongAnimal default constructor called ]" \
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type): type(type)
{
	std::cout << GREEN << "[ WrongAnimal parametrized constructor called ]" \
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << GREEN << "[ WrongAnimal copy-constructor called ]" \
		<< RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "[ WrongAnimal destructor called ]" \
		<< RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << GREEN << "[ WrongAnimal assignment operator called ]" \
		<< RESET << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "* GENERIC WRONG ANIMAL VOICES *" << std::endl;
}
