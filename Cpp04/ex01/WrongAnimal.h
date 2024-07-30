/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:06:28 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:22:42 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <string>
# include "defines.h"

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal& other);

	WrongAnimal&	operator=(const WrongAnimal& other);
	~WrongAnimal();

	void	makeSound(void);
};

#endif
