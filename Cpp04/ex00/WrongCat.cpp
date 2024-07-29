/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:23:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 00:10:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << GREEN << "[ WrongCat default constructor called ]" \
		<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << GREEN << "[ WrongCat copy constructor called ]" \
		<< RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	std::cout << GREEN << "[ WrongCat copy assignment operator called ]" \
		<< RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "[ WrongCat destructor called ]" \
		<< RESET << std::endl;
}

void	WrongCat::makeSound(void)
{
	std::cout << BLUE << "* MEOW *" << RESET << std::endl;
}