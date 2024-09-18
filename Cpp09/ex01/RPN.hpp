/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/18 16:41:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

# define ZERO '0'
# define ERROR_MSG "Error: Invalid RPN expression"

class RPN
{
	private:
		std::string		_expr;
		std::stack<int>	_stack;

		RPN(void);
		RPN(RPN const &other);
		RPN&	operator=(RPN const &other);
	public:
		RPN(std::string rpn);
		~RPN(void);

		void	calculate(void);
};

#endif