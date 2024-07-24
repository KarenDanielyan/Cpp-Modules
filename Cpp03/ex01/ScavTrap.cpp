/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:42:58 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 17:47:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "[ ScavTrap deafault constructor called ]" \
		<< RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "[ ScavTrap parametrized constructor called ]" \
		<< RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << GREEN << "[ ScavTrap copy constructor called ]" \
		<< RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "[ ScavTrap destructor called ]" \
		<< RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	this->_name = other._name;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << GREEN << "[ ScavTrap assignment operator called. ]" \
		<< RESET << std::endl;
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << _name << "is now in guardkeeper mode." \
		<< RESET << std::endl;
}
