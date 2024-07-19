/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:25:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 19:21:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.h"

static void	test(const Point &A, const Point &B, const Point &C, const Point &P, bool expected)
{
	bool	output;

	output = bsp(A, B, C, P);
	std::cout << BLUE << "-- Triangle Points --" << RESET << std::endl;
	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;
	std::cout << "C: " << C << std::endl;
	std::cout << YELLOW << "-- Point to Test --" << RESET << std::endl;
	std::cout << "P: " << P << std::endl;
	std::cout << "Excpected: ";
	if (expected == true)
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << expected << RESET << ", ";
	std::cout << "Got: ";
	if (output == true)
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << output << RESET << std::endl;
}

int main()
{
	std::cout << "-- TEST 1 --" << std::endl;
	test(Point(1, 1), Point(4, 1), Point(2, 5), Point(1.8, 3), true);
	std::cout << "-- TEST 2 --" << std::endl;
	test(Point(0, 0), Point(4, 0), Point(2, 4), Point(2, 2), true);
	std::cout << "-- TEST 3 --" << std::endl;
	test(Point(2, 1), Point(6, 1), Point(4, 5), Point(40, 2), false);
	std::cout << "-- TEST 4 --" << std::endl;
	test(Point(1, 1), Point(4, 1), Point(2, 5), Point(10, 3), false);
	std::cout << "-- TEST 5 --" << std::endl;
	test(Point(1, 1), Point(4, 1), Point(2, 5), Point(3, 2), true);
	std::cout << "-- TEST 6 --" << std::endl;
	test(Point(1, 1), Point(4, 1), Point(2, 5), Point(0, 0), false);
	std::cout << "-- TEST 7 --" << std::endl;
	test(Point(1, 1), Point(4, 1), Point(2, 5), Point(2, 1.10156), true);
	return 0;
}