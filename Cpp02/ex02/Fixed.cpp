/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:25:20 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 01:41:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

/*
 * 	Source: https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e
 */

/* ** Constructor ** */

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

Fixed::Fixed(const float f)
{
	std::cout << YELLOW << "[ Float constructor called. ]" << std::endl;
	raw_bits = roundf(f * (1 << fractional_bits));
}

Fixed::Fixed(const int i)
{
	std::cout << YELLOW "[ Int constructor called. ]" << std::endl;
	raw_bits = i * (1 << fractional_bits);
}

/* ** Destructor ** */

Fixed::~Fixed(void)
{
	std::cout << RED << "[ Destructor called ]" << RESET << std::endl;
}

/* ** Properties ** */

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

/* ** Type Casts ** */

float	Fixed::toFloat() const
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
int		Fixed::toInt() const
{
	return (raw_bits / (1 << fractional_bits));
}

/* ** Operators ** */

std::ostream	&operator<<(std::ostream &out, Fixed const &self)
{
	out << self.toFloat();
	return (out);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << YELLOW << "[ Copy assignment operator called ]" \
		<< RESET << std::endl;
	raw_bits = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (this->raw_bits + other.raw_bits);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (this->raw_bits - other.raw_bits);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->raw_bits * other.raw_bits);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->raw_bits / other.raw_bits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->raw_bits != other.raw_bits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->raw_bits == other.raw_bits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->raw_bits >= other.raw_bits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->raw_bits <= other.raw_bits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->raw_bits > other.raw_bits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->raw_bits < other.raw_bits);
}

