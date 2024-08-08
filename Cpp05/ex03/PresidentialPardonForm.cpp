/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:14:03 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 20:18:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(): \
		AForm("PresidentialPardonForm", 25, 5), _target("Carl")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): \
		AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( \
		const PresidentialPardonForm& other):
		AForm(other), _target(other._target)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(\
		const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "Dear " << _target << \
		" we would like to inform you that you " << \
		"have been pardoned by Zaphod Beeblebrox." << std::endl;
}

