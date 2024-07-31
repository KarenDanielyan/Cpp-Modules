/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:19:40 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/30 19:46:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <string>
# include "defines.h"

class	Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain& other);

	~Brain();

	Brain&	operator = (const Brain& other);
};

#endif
