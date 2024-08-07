/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:45:03 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/07 17:50:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.h"

class	Form
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_execute_grade;

public:
	Form();
	Form(const std::string &name, const int sign_grade, \
			const int execute_grade);
	Form(const Form& other);

	Form&	operator=(const Form& other);

	~Form();

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int	getSignGrade(void) const;
	int	getExecuteGrade(void) const;

	void		beSigned(Bureaucrat& signer);

	class	GradeTooHighException : public std::exception
	{
		public:
			const char*	what(void) const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			const char*	what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, Form& self);

#endif
