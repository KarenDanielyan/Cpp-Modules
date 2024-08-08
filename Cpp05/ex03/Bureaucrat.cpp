/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:59:58 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 19:49:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"

Bureaucrat::Bureaucrat(void): _name("Marvin"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): \
	_name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (--_grade < MAX_GRADE)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	if (++_grade > MIN_GRADE)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() \
			<< std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't sign " \
			<< form.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() \
			<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " \
			<< form.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Exception: Bureaucrat grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Exception: Bureaucrat grade is too low!";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &self)
{
	os << self.getName() << ", bureaucrat grade " << self.getGrade();
	return (os);
}

