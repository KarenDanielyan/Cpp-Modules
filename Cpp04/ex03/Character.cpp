/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:48:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 20:35:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "defines.h"
#include <iostream>

Character::Character(void): _name("bob")
{
	std::cout << GREEN << CHAR_DEFAULT << RESET << std::endl;
}

Character::Character(const std::string& name): _name(name)
{
	std::cout << GREEN << CHAR_PARAM << RESET << std::endl;
}

Character::Character(const Character& other): _name(other._name)
{
	for (int i = 0; i < 4; i ++)
		_inventory[i] = other._inventory[i]->clone();
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

	for (i = 0; _inventory[i] != NULL && i < 4; i ++)
		;
	if (_inventory[i] != NULL)
		std::cout << YELLOW << CHAR_EQUIP_WARN << RESET << std::endl;
	else
	{
		std::cout << BLUE << "Character " << _name << " equipped " \
			<< m->getType() << RESET << std::endl;
		_inventory[i] = m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		std::cout << BLUE << "Character " << _name << " unequipped " \
			<< _inventory[idx]->getType() << RESET << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << YELLOW << CHAR_IDX_WARN << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << YELLOW << CHAR_IDX_WARN << RESET << std::endl;
	else
		_inventory[idx]->use(target);
}

