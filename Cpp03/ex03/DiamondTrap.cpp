/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:54:57 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 19:08:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(): _name("Carl")
{
	std::cout << GREEN << "[ DiamondTrap default constructor called ]" \
		<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
	std::cout << GREEN << "[ DiamondTrap parametrized constructor called ]" \
		<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), \
	ScavTrap(other), FragTrap(other)
{
	std::cout << GREEN << "[ DiamondTrap copy constructor called ]" \
		<< RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "[ DiamondTrap destructor called ]" \
		<< RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::_name = other.ClapTrap::_name + "_clap_name";
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

void	DiamondTrap::whoamI()
{
	std::cout << "I am " << _name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}
