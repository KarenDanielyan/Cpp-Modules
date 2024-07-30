/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:04:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:57:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.h"
# include "Brain.h"

class	Dog: public Animal
{
private:
	Brain*	_brain;
public:
	Dog(void);
	Dog(const Dog& other);

	~Dog(void);

	Dog&	operator=(const Dog& other);

	void	makeSound(void);
};

#endif
