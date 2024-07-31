/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/31 14:03:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <string>
# include "defines.h"

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal(void);
	AAnimal(const std::string type);
	AAnimal(const AAnimal& other);

	AAnimal&	operator=(const AAnimal& other);
	virtual ~AAnimal();

	virtual void	makeSound(void) = 0;
};

#endif
