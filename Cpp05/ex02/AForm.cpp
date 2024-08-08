/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:56:26 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 16:45:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"

AForm::AForm(void): _name("Default"), _is_signed(false), \
					_sign_grade(MIN_GRADE), _execute_grade(MIN_GRADE)
{}

AForm::AForm(const std::string& name, const int sign_grade, \
			const int execute_grade): \
			_name(name), _is_signed(false), _sign_grade(sign_grade), \
			_execute_grade(execute_grade)
{
	if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other): _name(other._name), \
				_is_signed(other._is_signed), _sign_grade(other._sign_grade), \
				_execute_grade(other._execute_grade)
{}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_is_signed);
}

int	AForm::getSignGrade(void) const
{
	return (_sign_grade);
}

int	AForm::getExecuteGrade(void) const
{
	return (_execute_grade);
}

void	AForm::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > _sign_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_is_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (_is_signed == false)
		throw ExecuteOnUnsignedException();
	if (executor.getGrade() > _execute_grade)
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Form grade is too high!");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Form grade is too low!");
}

const char*	AForm::ExecuteOnUnsignedException::what(void) const throw()
{
	return ("Exception: Attempting to execute unsigned form!");
}

std::ostream&	operator<<(std::ostream& os, AForm& self)
{
	os << self.getName() << " form, sign grade " << self.getSignGrade() << \
		", execution grade " << self.getExecuteGrade() << \
		(self.getIsSigned() == true ? ", is signed" : ", is not signed");
	return (os);
}

