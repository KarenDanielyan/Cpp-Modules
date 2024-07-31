/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:12 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 20:00:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>
# include "ICharacter.h"

class	ICharacter;

class	AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);

	AMateria&	operator=(const AMateria& other);

	virtual ~AMateria();

	std::string const &	getType(void) const;
	virtual void		use(ICharacter& target) = 0;
	virtual AMateria*	clone(void) const = 0;
};

#endif
