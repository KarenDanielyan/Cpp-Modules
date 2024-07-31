/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:21:58 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 19:22:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "defines.h"
#include "Ice.h"

Ice::Ice(void): AMateria("ice")
{
	std::cout << GREEN << ICE_DEFAULT << RESET << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	std::cout << GREEN << ICE_COPY << RESET << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	this->type = other.type;
	std::cout << GREEN << ICE_ASSIGN << RESET << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << RED << ICE_DESTR << RESET << std::endl;
}

void		Ice::use(ICharacter& target)
{
	std::cout << CYAN << ICE_USE << target.getName() << " *" \
			<< RESET << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}
