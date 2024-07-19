/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:25:20 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 19:37:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

/*
 * 	Source: https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e
 */

/* ** Constructor ** */

Fixed::Fixed(void): raw_bits(0) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const float f)
{
	raw_bits = roundf(f * (1 << fractional_bits));
}

Fixed::Fixed(const int i)
{
	raw_bits = i * (1 << fractional_bits);
}

/* ** Destructor ** */

Fixed::~Fixed(void) {}

/* ** Properties ** */

int	Fixed::getRawBits(void) const
{
	return (this->raw_bits);
}

void	Fixed::setRawBits(int raw)
{
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
	raw_bits = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	temp;

	temp.raw_bits = this->raw_bits + other.raw_bits;
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;

	temp.raw_bits = this->raw_bits - other.raw_bits;
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
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

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->raw_bits += 1;
	return (temp);
}

Fixed	Fixed::operator++()
{
	this->raw_bits += 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->raw_bits -= 1;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->raw_bits -= 1;
	return (*this);
}

/* ** Compare methods ** */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
