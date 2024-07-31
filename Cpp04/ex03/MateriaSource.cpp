/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:30:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 21:47:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include "defines.h"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << GREEN << MATS_DEFAULT << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i]->clone();
	std::cout << GREEN << MATS_COPY << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	std::cout << GREEN << MATS_ASSIGN << RESET << std::endl;
	return(*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << RED << MATS_DESTR << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] == materia)
			return;
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			std::cout << BLUE << MATS_LEARN << RESET << std::endl;
			return ;
		}
	}
	std::cout << YELLOW << MATS_2BIG << RESET << std::endl;
}

AMateria* MateriaSource::createMateria (std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	std::cout << YELLOW << MATS_INV_TYPE << RESET << std::endl;
	return (NULL);
}

