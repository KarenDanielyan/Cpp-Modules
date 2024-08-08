/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:34:21 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 20:45:39 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.h"

class	Intern
{
public:
	Intern();
	Intern(const Intern& other);

	Intern&	operator=(const Intern& other);

	~Intern();

	AForm*	makeForm(std::string name, std::string target) const;

	enum	FormType_e
	{
		SHRUBBERYCREATION,
		ROBOTOMYREQUEST,
		PRESIDENTIALPARDON
	};
};

#endif
