/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:34:10 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/21 23:31:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	robot_1("rob-bot");
	ClapTrap	robot_2;

	robot_1.attack("tree");
	robot_1.attack("enemy");
	robot_1.attack("another enemy");
	robot_1.takeDamage(1);
	robot_1.takeDamage(1);
	robot_1.takeDamage(10);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_1.beRepaired(2);
	robot_2 = robot_1;
	return (0);
}