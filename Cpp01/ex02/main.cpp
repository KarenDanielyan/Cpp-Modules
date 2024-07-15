/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:50:21 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/15 15:22:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout << "String Address   : " << &string << std::endl;
	std::cout << "Pointer Value    : " << stringPTR << std::endl;
	std::cout << "Pointer Address  : " << &stringPTR << std::endl;
	std::cout << "Reference Address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String Value         : " << string << std::endl;
	std::cout << "Value under pointer  : " << *stringPTR << std::endl;
	std::cout << "Value under reference: " << stringREF << std::endl;
	return (0);
}