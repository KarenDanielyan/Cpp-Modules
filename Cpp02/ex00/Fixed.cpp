/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:25:20 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/18 21:10:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

Fixed::Fixed(void): raw_bits(0)
{
	std::cout << GREEN << "[ Default constructor called ]" << \
		RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << BLUE << "[ Copy constructor called ]" << \
		RESET << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << RED << "[ Destructor called ]" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << YELLOW << "[ Copy assignment operator called ]" \
		<< RESET << std::endl;
	raw_bits = other.getRawBits();
	return (*this);
}


int	Fixed::getRawBits(void) const
{
	std::cout << "[ getRawBits() member function called ]" << std::endl;
	return (this->raw_bits);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "[ setRawBits() member function called ]" << std::endl;
	this->raw_bits = raw;
}