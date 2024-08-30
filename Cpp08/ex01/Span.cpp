/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:58:20 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/31 03:08:28 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

static	int	my_rand(void);

Span::Span() : _filled(0) {}

Span::Span(unsigned int N) : _array(N), _filled(0) {}

Span::~Span() {}

Span::Span(Span const &other) : _array(other._array), _filled(other._filled) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_array = other._array;
		_filled = other._filled;
	}
	return (*this);
}

std::vector<int> const &	Span::getArray(void) const
{
	return (_array);
}

void	Span::fill(unsigned int N)
{
	if (N > _array.size() - _filled)
		throw SpanException();
	srand(time(NULL));
	std::generate(_array.begin() + _filled, 
				_array.begin() + _filled + N, 
				&my_rand);
	_filled += N;
}

void Span::addNumber(int number)
{
	if (_filled >= _array.size())
		throw SpanException();
	_array[_filled++] = number;
}

int	Span::shortestSpan(void)
{
	if (_filled < 2)
		throw (std::out_of_range("Error: Span is too short"));
	std::sort(_array.begin(), _array.begin() + _filled);
	int	span = _array[1] - _array[0];
	for (unsigned int i = 2; i < _filled; i++)
	{
		if (_array[i] - _array[i - 1] < span)
			span = _array[i] - _array[i - 1];
	}
	return (span);
}

int	Span::longestSpan(void)
{
	if (_filled < 2)
		throw (std::out_of_range("Error: Span is too short!"));
	std::sort(_array.begin(), _array.begin() + _filled);
	return (_array[_filled - 1] - _array[0]);
}

const char*	Span::SpanException::what() const throw()
{
	return ("Error: Span is full!");
}

const char*	Span::InvalidSpanTypeException::what() const throw()
{
	return ("Error: Invalid iterator type!");
}

std::ostream & operator<<(std::ostream &o, Span const &span)
{
	std::vector<int> const & array = span.getArray();
	for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); it++)
		o << *it << " ";
	return (o);
}

static	int	my_rand(void)
{
	return (rand() % 1000);
}