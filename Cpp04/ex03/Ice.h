/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:17:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 17:50:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.h"

class	Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);

	Ice&	operator=(const Ice& other);

	~Ice();

	void		use(ICharacter& target);
	AMateria*	clone(void) const;
};

#endif
