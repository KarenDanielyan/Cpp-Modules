/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:54:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 17:50:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.h"

Base*	generate(void)
{
	int	rand;

	rand = std::rand() % 3;
	switch (rand)
	{
		case 0:
			return (new A());
			break ;
		case 1:
			return (new B());
			break ;
		case 2:
			return (new C());
			break ;
	}
	return (NULL);
}

void	identify(Base *p)
{
	Base*		ptr[3];
	std::string	types[3];
	int			i;

	i = -1;
	types[0] = "A";
	types[1] = "B";
	types[2] = "C";
	ptr[0] = dynamic_cast<A*>(p);
	ptr[1] = dynamic_cast<B*>(p);
	ptr[2] = dynamic_cast<C*>(p);
	while (ptr[++i] == NULL)
		;
	std::cout << "Actual type is: " << types[i] << std::endl;
}

void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "Actual type is: A" << std::endl;
	}
	catch(...)
	{}
	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "Actual type is: B" << std::endl;
	}
	catch(...)
	{}
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "Actual type is: C" << std::endl;
	}
	catch(...)
	{}
}