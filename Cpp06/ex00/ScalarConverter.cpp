/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:56:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/15 21:09:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>

ScalarConverter::ScalarConverter(const std::string& input, int flags): \
		_input(input), _flags(flags)
{}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(void) const
{
	std::cout << "It will do something soon" << std::endl;
}
