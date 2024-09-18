/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:20:19 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/18 18:17:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

RPN::RPN(void) {}

RPN::RPN(const RPN &other): _expr(other._expr){}

RPN::RPN(std::string rpn)
{
	for (std::string::iterator it = rpn.begin(); it != rpn.end(); it++)
	{
		if (*it == ' ')
			rpn.erase(it);
		if (!std::isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/')
			throw std::invalid_argument(ERROR_MSG);
	}
	_expr = rpn;
}

RPN::~RPN(void) {}

RPN&	RPN::operator=(const RPN &other)
{
	_expr = other._expr;
	return (*this);
}

void	RPN::calculate(void)
{
	int	lhs;
	int	rhs;

	for (size_t i = 0; i < _expr.length(); i++)
	{
		if (std::isdigit(_expr[i]))
			_stack.push(_expr[i] - ZERO);
		else if (_stack.size() < 2)
			throw std::runtime_error(ERROR_MSG);
		else
		{
			rhs = _stack.top();
			_stack.pop();
			lhs = _stack.top();
			_stack.pop();
			switch(_expr[i])
			{
				case '+':
					_stack.push(lhs + rhs);
					break;
				case '-':
					_stack.push(lhs - rhs);
					break;
				case '*':
					_stack.push(lhs * rhs);
					break;
				case '/':
					_stack.push(lhs / rhs);
					break;
			}
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error(ERROR_MSG);
	std::cout << _stack.top() << std::endl;
}