/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:36:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 20:57:04 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
		;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string name, std::string target) const
{
	int					type;
	const std::string	types[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	for (type = 0; type < 4; type ++)
	{
		if (type < 3 && types[type] == name)
		{
			std::cout << "Intern creates " << types[type] << " form." \
				<< std::endl;
			break ;
		}
	}
	switch (type)
	{
		case SHRUBBERYCREATION:
			return (new ShrubberyCreationForm(target));
		case ROBOTOMYREQUEST:
			return (new RobotomyRequestForm(target));
		case PRESIDENTIALPARDON:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern is not aware of this type of form." \
				<< std::endl;
			return (NULL);
	}
}
