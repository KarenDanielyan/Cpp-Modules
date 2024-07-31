/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:49:19 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 21:52:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include "Character.h"
#include "Ice.h"
#include "Cure.h"

void	atexit(void)
{
	system("leaks ex03");
}

int main()
{	
	IMateriaSource*	src = new MateriaSource();
	Ice*			ice = new Ice();
	AMateria*		tmp;

	std::atexit(&atexit);
	src->learnMateria(ice);
	src->learnMateria(new Cure());
	src->learnMateria(ice);
	src->learnMateria(ice);
	ICharacter* me = new Character("me");
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(-12);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
