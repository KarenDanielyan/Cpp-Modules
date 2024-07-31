/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:30:08 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 19:52:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.h"
# include <string>

class	Character : public ICharacter
{
private:
	std::string	_name;
	AMateria*	_inventory[4];
public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);

	Character&	operator=(const Character& other);

	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
