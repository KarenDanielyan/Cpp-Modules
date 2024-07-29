/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/29 16:03:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(const Animal& other);

	Animal&	operator=(const Animal& other);
	~Animal();

	virtual void	makeSound(void);
};

#endif
