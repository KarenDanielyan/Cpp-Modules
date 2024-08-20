/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:56:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 02:23:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <climits>

static void	convert_literals(std::string &input, int flags)
{
	size_t	pos;

	pos = input.rfind('f');
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: " << input;
	if (flags & DOUBLE)
	{
		std::cout << 'f' << std::endl;
		std::cout << "Double: " << input << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Double: " << input.substr(0, pos) << std::endl;
	}
}

void	ScalarConverter::convert(std::string& input, int flags)
{
	double	d;

	if (flags & LITERAL)
		convert_literals(input, flags);
	if (flags & CHAR)
		d = static_cast<double>(input[0]);
	else
		d = std::atof(input.c_str());
	std::cout << "Char: ";
	if (d > CHAR_MAX || d < 0)
		std::cout << "Impossible" << std::endl;
	else if ((d >= 0 && d < ' ') || d >= 126)
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "Int: ";
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "Float: ";
	if (d > __FLT_MAX__ || d < -__FLT_MAX__)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << std::endl;
	std::cout << "Double: " << d << std::endl;
}
