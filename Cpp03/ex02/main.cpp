/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:34:10 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/24 18:04:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

int main()
{
	FragTrap robot_1("rob-bot");
	FragTrap robot_3("Jack");

	robot_1.status();
	robot_1.attack("tree");
	robot_1.attack("enemy");
	robot_1.attack("another enemy");
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_3.attack("test test");
	robot_3.highFivesGuys();
	robot_3.status();
	return (0);
}