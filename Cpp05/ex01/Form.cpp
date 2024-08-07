/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:56:26 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/07 18:41:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

Form::Form(void): _name("Default"), _is_signed(false), \
					_sign_grade(MIN_GRADE), _execute_grade(MIN_GRADE)
{}

Form::Form(const std::string& name, const int sign_grade, \
			const int execute_grade): \
			_name(name), _is_signed(false), _sign_grade(sign_grade), \
			_execute_grade(execute_grade)
{
	if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form& other): _name(other._name), \
				_is_signed(other._is_signed), _sign_grade(other._sign_grade), \
				_execute_grade(other._execute_grade)
{}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

Form::~Form(void) {}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_is_signed);
}

int	Form::getSignGrade(void) const
{
	return (_sign_grade);
}

int	Form::getExecuteGrade(void) const
{
	return (_execute_grade);
}

void	Form::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > _sign_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_is_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Form grade is too high!");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Form grade is too low!");
}

std::ostream&	operator<<(std::ostream& os, Form& self)
{
	os << self.getName() << " form, sign grade " << self.getSignGrade() << \
		", execution grade " << self.getExecuteGrade() << \
		(self.getIsSigned() == true ? ", is signed" : ", is not signed");
	return (os);
}

