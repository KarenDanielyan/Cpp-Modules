/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:31:08 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 18:04:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(): _name("Carl"), \
	_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "[ ClapTrap deafault constructor called. ]" \
		<< RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), \
	_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "[ ClapTrap parametrized constructor called. ]" \
		<< RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), \
	_hit_points(other._hit_points), _energy_points(other._hit_points), \
	_attack_damage(other._attack_damage)
{
	std::cout << GREEN << "[ ClapTrap copy constructor called. ]" \
		<< RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "[ ClapTrap destructor called. ]" \
		<< RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._hit_points;
	this->_attack_damage = other._attack_damage;
	std::cout << GREEN << "[ ClapTrap assignment operator called. ]" \
		<< RESET << std::endl;
	return (*this);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " has taken " << \
			amount << " points of damage!" << RESET << std::endl;
		_hit_points -= amount;
		if (_hit_points <= 0)
			std::cout << RED << "ClapTrap " << _name << " died!" \
				<< RESET << std::endl;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " is dead.." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << BLUE << "ClapTrap " << _name << " attacks " << \
			target << ", causing " << _attack_damage << " points of damage!" \
			<< RESET << std::endl;
		_energy_points --;
		if (_energy_points <= 0)
			std::cout << RED << "ClapTrap " << _name << "has no energy!" \
				<< RESET << std::endl;
	}

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " repaired " \
			<< amount << " hit points." << RESET << std::endl;
		_energy_points --;
		if (_energy_points <= 0)
			std::cout << RED << "ClapTrap " << _name << "depleted its energy" \
			<< RESET << std::endl;
	}
	else if (_hit_points < 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is dead.." << std::endl;
	}
	else if (_energy_points < 0)
	{
		std::cout << RED << "ClapTrap " << _name << "has no energy!" \
			<< RESET << std::endl;
	}
}

void	ClapTrap::status()
{
	std::cout << CYAN << _name << " status info" << std::endl;
	std::cout << "Health Points: " << _hit_points << std::endl;
	std::cout << "Energy Points: " << _energy_points << std::endl;
	std::cout << "Attack Damage: " << _attack_damage \
		<< RESET << std::endl;
}

