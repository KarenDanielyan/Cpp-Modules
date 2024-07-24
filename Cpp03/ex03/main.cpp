/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:34:10 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 19:13:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

int main()
{
	ClapTrap	robot_1("rob-bot");
	ClapTrap	robot_2;
	ClapTrap	*ptr;

	ScavTrap	*robot_3 = new ScavTrap("vally");

	FragTrap	robot_4("FragTrap robot");

	DiamondTrap	*diamond_robot = new DiamondTrap("diamond_name_long");

	ptr = robot_3;
	robot_1.attack("tree");
	robot_1.attack("enemy");
	robot_1.attack("another enemy");
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_1.status();

	robot_2 = robot_1;
	robot_2.status();

	robot_3->attack("wall");
	delete ptr;

	robot_4.attack("test test");
	robot_4.highFivesGuys();

	diamond_robot->status();
	delete diamond_robot;

	return (0);	
}