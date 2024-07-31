/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:20:49 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 18:56:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.h"

class	Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& other);

	Cure&	operator=(const Cure& other);

	~Cure();

	void		use(ICharacter& target);
	AMateria*	clone(void) const;
};

#endif
