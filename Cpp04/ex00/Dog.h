/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:04:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/29 23:54:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.h"

class	Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& other);

		~Dog(void);

		Dog&	operator=(const Dog& other);

		void	makeSound(void);
};

#endif
