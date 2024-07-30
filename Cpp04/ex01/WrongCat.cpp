/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:23:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:34:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << GREEN << WCAT_DFLT \
		<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << GREEN << WCAT_COPY \
		<< RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	std::cout << GREEN << WCAT_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << WCAT_DESTR \
		<< RESET << std::endl;
}

void	WrongCat::makeSound(void)
{
	std::cout << BLUE << WCAT_SOUND << RESET << std::endl;
}
