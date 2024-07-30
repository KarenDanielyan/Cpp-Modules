/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:24:52 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:55:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <iostream>

Brain::Brain(void)
{
	std::cout << GREEN << BRAIN_DFLT << RESET << std::endl;
	for (int i = 0; i < 100; i ++)
		ideas[i] = DEFAULT_IDEAS;
}

Brain::Brain(const Brain& other)
{
	std::cout << GREEN << BRAIN_COPY << RESET << std::endl;
	for (int i = 0; i < 100; i ++)
		ideas[i] = (other.ideas)[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << GREEN << BRAIN_ASSGN << RESET << std::endl;
	for (int i = 0; i < 100; i ++)
		this->ideas[i] = (other.ideas)[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << RED << BRAIN_DESTR << RESET << std::endl;
}
