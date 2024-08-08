/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:02:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 20:13:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(): \
		AForm("RobotomyRequestForm", 72, 45), _target("Carl")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): \
		AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( \
		const RobotomyRequestForm& other):
		AForm(other), _target(other._target)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(\
		const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static bool	rng = true;

	AForm::execute(executor);
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "Dear " << _target;
	if (rng)
		std::cout << ", you are successfully robotomized." << std::endl;
	else
		std::cout << ", unfortunately romotomy failed." << std::endl;
	rng ^= true;
}

