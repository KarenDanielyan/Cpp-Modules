/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:06:51 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 19:29:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "defines.h"
#include "AMateria.h"

AMateria::AMateria(void): type("default")
{
	std::cout << GREEN << AMAT_DEFAULT << RESET << std::endl;
}

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << GREEN << AMAT_PARAM << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	std::cout << GREEN << AMAT_COPY << RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	this->type = other.type;
	std::cout << GREEN << AMAT_ASSIGN << RESET << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << RED << AMAT_DESTR << RESET << std::endl;
}

std::string const &	AMateria::getType(void) const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << AMAT_USE << target.getName() << " *" << std::endl;
}
