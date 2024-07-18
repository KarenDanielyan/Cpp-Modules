/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:25:20 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/18 21:56:36 by kdaniely         ###   ########.fr       */
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

std::ostream	&operator<<(std::ostream out, const Fixed &self)
{
	return "42";
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

float	Fixed::toFloat()
{
	float	f_rep;

	f_rep = static_cast<float>(raw_bits);
	return (f_rep / (1 << fractional_bits));
}

/*
 * NOTE:	1 / (1 << n) is the same operation as 1 >> n, but in this case
 * 			we will have memory overflow from the stack segments before the 
 * 			variable.
 */
int		Fixed::toInt()
{
	return (raw_bits / (1 << fractional_bits));
}
