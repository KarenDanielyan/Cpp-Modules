/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:41:17 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/31 03:09:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.h"

int	main(void)
{
	Span	sp(10);
	std::vector<int>			vi(4);
	std::vector<std::string>	vs(3);

	for (int i = 0; i < 4; i++)
		vi[i] = i;
	try
	{
		std::cout << "Filling Span with 5 random numbers" << std::endl;
		sp.fill(5);
		std::cout << sp << std::endl;
		std::cout << "Filling Span with 4 numbers from vector" << std::endl;
		sp.fill(vi.begin(), vi.end());
		std::cout << sp << std::endl;
		std::cout << "Trying to fill Span with 3 strings" << std::endl;
		sp.fill(vs.begin(), vs.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Let's see if we have space left" << std::endl;
		sp.addNumber(42);
		std::cout << sp << std::endl;
		sp.addNumber(6041);
		std::cout << sp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	return (0);
}