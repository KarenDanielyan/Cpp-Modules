/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:34:10 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 17:25:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main()
{
	ScavTrap	robot_1("rob-bot");
	ScavTrap	robot_2;

	robot_1.attack("tree");
	robot_1.attack("enemy");
	robot_1.attack("another enemy");
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_2 = robot_1;

	return (0);
}