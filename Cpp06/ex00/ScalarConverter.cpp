/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:56:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/16 18:12:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>

void	ScalarConverter::convert(std::string& input, int flags)
{
	size_t	pos;
	if (flags & LITERAL)
	{
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
	std::cout << "Apart from literals, convert doesn't do anything yet ))." << std::endl;
}
