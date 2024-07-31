/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:58:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 14:02:04 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.h"
#include <iostream>

AAnimal::AAnimal(void): type("Bob")
{
	std::cout << GREEN << ANIMAL_DFLT \
		<< RESET << std::endl;
}

AAnimal::AAnimal(const std::string type): type(type)
{
	std::cout << GREEN << ANIMAL_PARAM \
		<< RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): type(other.type)
{
	std::cout << GREEN << ANIMAL_COPY \
		<< RESET << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << RED << ANIMAL_DESTR \
		<< RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal& other)
{
	this->type = other.type;
	std::cout << GREEN << ANIMAL_ASSGN \
		<< RESET << std::endl;
	return (*this);
}

