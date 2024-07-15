/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:33:31 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/15 17:08:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string type): type(type) {}

const	std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}