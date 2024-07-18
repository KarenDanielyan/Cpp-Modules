/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:24:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 01:38:13 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <string>

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define RESET "\033[0m"

class Fixed
{
	private:
		int					raw_bits;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const float f);
		Fixed(const int i);

		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const ;
		void	setRawBits(int const raw);

		Fixed	&operator=(const Fixed &other);

		bool	operator!=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
};


std::ostream	&operator<<(std::ostream &out, Fixed const &self);

#endif