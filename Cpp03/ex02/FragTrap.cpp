/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:55:51 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 17:59:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "[ FragTrap deafault constructor called ]" \
		<< RESET << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << GREEN << "[ FragTrap parametrized constructor called ]" \
		<< RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << GREEN << "[ FragTrap copy constructor called ]" \
		<< RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "[ FragTrap destructor called ]" \
		<< RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	this->_name = other._name;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << GREEN << "[ FragTrap assignment operator called. ]" \
		<< RESET << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << BLUE << "FragTrap " << _name << " highfives everyone." \
		<< RESET << std::endl;
}
