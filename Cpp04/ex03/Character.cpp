/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:48:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/02 16:31:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "defines.h"
#include <iostream>

Character::Character(void): _name("bob")
{
	for (int i = 0; i < 4; i ++)
		_inventory[i] = NULL;
	std::cout << GREEN << CHAR_DEFAULT << RESET << std::endl;
}

Character::Character(const std::string& name): _name(name)
{
	for (int i = 0; i < 4; i ++)
		_inventory[i] = NULL;
	std::cout << GREEN << CHAR_PARAM << RESET << std::endl;
}

Character::Character(const Character& other): _name(other._name)
{
	for (int i = 0; i < 4; i ++)
	{
		_inventory[i] = NULL;
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << GREEN << CHAR_COPY << RESET << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	if (this == &other)
			return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i ++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << GREEN << CHAR_ASSIGN << RESET << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i ++)
		delete _inventory[i];
	std::cout << RED << CHAR_DESTR << RESET << std::endl;
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	for (i = 0; i < 4 && _inventory[i] != NULL; i ++)
		;
	if (i > 3 || _inventory[i] != NULL)
		std::cout << YELLOW << CHAR_EQUIP_WARN << RESET << std::endl;
	else if (m != NULL)
	{
		std::cout << BLUE << "Character " << _name << " equipped " \
			<< m->getType() << RESET << std::endl;
		if (inInventory(m) == true)
			_inventory[i] = m->clone();
		else
			_inventory[i] = m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (_inventory[idx] != NULL)
		{
			std::cout << BLUE << "Character " << _name << " unequipped " \
				<< _inventory[idx]->getType() << RESET << std::endl;
			_inventory[idx] = NULL;
		}
	}
	else
		std::cout << YELLOW << CHAR_IDX_WARN << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << YELLOW << CHAR_IDX_WARN << RESET << std::endl;
	else if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << YELLOW << "Warning: No materia under that slot!" << RESET << std::endl;
}

bool	Character::inInventory(AMateria *m) const
{
	if (m)
	{
		for (int i = 0; i < 4; i ++)
		{
			if (_inventory[i] == m)
				return (true);
		}
	}
	return (false);
}

