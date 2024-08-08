/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:12:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 16:27:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.h"

class	ShrubberyCreationForm : public AForm
{
private:
	std::string					_target;
	static const std::string	_shrubbery;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void	execute(Bureaucrat const & executor) const;
};

#endif
