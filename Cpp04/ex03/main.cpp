/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:49:19 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/01 21:22:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include "Character.h"
#include "Ice.h"
#include "Cure.h"

int main()
{	
	IMateriaSource*	src = new MateriaSource();
	Ice*			ice = new Ice();
	AMateria*		tmp;

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
	me->unequip(3);
	delete tmp;
	tmp = src->createMateria("ice");
	me->unequip(-12);
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
