/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:15:25 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/30 18:35:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int> vec;

	vec.push_back(4323);
	vec.push_back(-65);
	vec.push_back(123);
	vec.push_back(4);
	vec.push_back(-432);

	std::cout << "\nTEST 1" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << *it << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nTEST 2" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 7);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}