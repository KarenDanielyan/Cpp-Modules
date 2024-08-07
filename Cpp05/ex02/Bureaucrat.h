/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:06:04 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/07 20:03:44 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <exception>
# include <iostream>

const int	MIN_GRADE = 150;
const int	MAX_GRADE = 1;

class	AForm;

class	Bureaucrat
{
private:
	const	std::string	_name;
	int		_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);

	Bureaucrat&	operator=(const Bureaucrat& other);

	~Bureaucrat();

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setGrade(int grade);

	void		incrementGrade(void);
	void		decrementGrade(void);

	void		signForm(AForm& form);

	class	GradeTooHighException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &other);

#endif
