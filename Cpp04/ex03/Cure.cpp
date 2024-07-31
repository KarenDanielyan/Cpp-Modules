/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:52:03 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 19:23:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include "defines.h"
#include <iostream>

Cure::Cure(void): AMateria("cure")
{
	std::cout << GREEN << CURE_DEFAULT << RESET << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	std::cout << GREEN << CURE_COPY << RESET << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	this->type = other.type;
	std::cout << GREEN << CURE_ASSIGN << RESET << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << RED << CURE_DESTR << RESET << std::endl;
}

void	Cure::use(ICharacter& target)
{
	std::cout << CYAN << CURE_USE1 << target.getName() << CURE_USE2 \
			<< RESET << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}
