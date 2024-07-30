/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 20:24:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include "defines.h"

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal& other);

	Animal&	operator=(const Animal& other);
	virtual ~Animal();

	virtual void	makeSound(void);
};

#endif
