/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:56:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 18:23:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <string>
#include <strstream>
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

static void	convert_float(double d)
{
	std::ostrstream	str;
	std::string		input;

	if (d > __FLT_MAX__ || d < -__FLT_MAX__)
		std::cout << "Impossible" << std::endl;
	else
	{
		str << d;
		input = str.str();
		if (input.find('.') != std::string::npos)
			std::cout << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << static_cast<float>(d) << ".0f" << std::endl;
	}
}

static void	convert_double(double d)
{
	std::ostrstream	str;
	std::string		input;
	
	str << d;
	input = str.str();
	if (input.find('.') != std::string::npos)
		std::cout << d << std::endl;
	else
		std::cout << d << ".0" << std::endl;
}

void	ScalarConverter::convert(std::string& input, int flags)
{
	double	d;

	if (flags & LITERAL)
		return (convert_literals(input, flags));
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
	convert_float(d);
	std::cout << "Double: ";
	convert_double(d);
	
}
