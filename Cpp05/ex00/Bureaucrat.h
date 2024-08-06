/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:06:04 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/06 20:06:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

class	Bureaucrat
{
private:

protected:

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);

	Bureaucrat&	operator=(const Bureaucrat& other);

	~Bureaucrat();
};

#endif
