/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 17:07:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_H
# define CLASSES_H

# include <iostream>
# include <exception>
# include <string>
# include <ctime>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*	generate(void);

void	identify(Base* p);

void	identify(Base& p);

#endif