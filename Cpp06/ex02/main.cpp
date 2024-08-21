/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:43:52 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 17:52:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Classes.h"

int	main(void)
{
	Base	*b;
	Base	*a;
	Base	*c;

	a = new A();
	c = new C();
	identify(a);
	for (int i = 0; i < 3; i ++)
	{
		b = generate();
		identify(*b);
		delete b;
	}
	identify(c);
	delete a;
	delete c;
	return (0);
}
