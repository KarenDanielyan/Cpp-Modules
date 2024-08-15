/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:51:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/15 21:00:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class	ScalarConverter
{
private:
	std::string	_input;
	int			_flags;

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);

	ScalarConverter&	operator=(const ScalarConverter& other);
public:
	ScalarConverter(const std::string& input, int flags);
	~ScalarConverter();

	void	convert(void) const;

	enum	ConvertibleTypes_e
	{
		CHAR	= (1 << 0),
		INT		= (1 << 1),
		FLOAT	= (1 << 2),
		DOUBLE	= (1 << 3)
	};
};

#endif
