/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:27:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(void): type("Bob")
{
	std::cout << GREEN << WANIMAL_DFLT \
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type): type(type)
{
	std::cout << GREEN << WANIMAL_PARAM \
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << GREEN << WANIMAL_COPY \
		<< RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << WANIMAL_DESTR \
		<< RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << GREEN << WANIMAL_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << WANIMAL_SOUND << std::endl;
}
