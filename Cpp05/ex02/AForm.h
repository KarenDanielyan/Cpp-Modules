/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:45:03 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/07 20:09:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.h"

class	AForm
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_execute_grade;

public:
	AForm();
	AForm(const std::string &name, const int sign_grade, \
			const int execute_grade);
	AForm(const AForm& other);

	AForm&	operator=(const AForm& other);

	~AForm();

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int	getSignGrade(void) const;
	int	getExecuteGrade(void) const;

	void			beSigned(Bureaucrat& signer);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream&	operator<<(std::ostream& os, AForm& self);

#endif
