/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:51:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/16 17:19:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include "Application.h"
# include <string>

class	ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);

	ScalarConverter&	operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static void	convert(std::string& input, int flags);
};

#endif
