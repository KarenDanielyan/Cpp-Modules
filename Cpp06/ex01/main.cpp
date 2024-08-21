/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:14:12 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.h"

int main() {
	Data data = {124, 42, "A"};
	Data* ptr = &data;

	uintptr_t serializedPtr = Serializer::serialize(ptr);
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);
	std::cout << "Original pointer: " << ptr << std::endl;
	std::cout << "Serialized pointer: " << serializedPtr << std::endl;
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
	if (ptr == deserializedPtr)
	{
		std::cout << "Serialization and deserialization successful." << std::endl;
	}
	else
	{
		std::cout << "Serialization and deserialization failed." << std::endl;
	}	
	return 0;
}