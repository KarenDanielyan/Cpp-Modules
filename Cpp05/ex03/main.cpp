/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:06:21 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/08 20:52:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "Intern.h"

int main(void)
{
	Intern  someRandomIntern;
	AForm*   rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery reques", "bender");
	delete rrf;
}
