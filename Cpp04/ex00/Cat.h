/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:18:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/29 23:54:39 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.h"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat& other);

	~Cat(void);

	Cat&	operator=(const Cat& other);

	void	makeSound(void);
};

#endif