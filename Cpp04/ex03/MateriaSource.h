/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:21:22 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 21:40:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.h"

class	MateriaSource: public IMateriaSource
{
private:
	AMateria*	_inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);

	MateriaSource&	operator=(const MateriaSource& other);

	~MateriaSource();
	void			learnMateria(AMateria*);
	AMateria*		createMateria(std::string const & type);
};

#endif
