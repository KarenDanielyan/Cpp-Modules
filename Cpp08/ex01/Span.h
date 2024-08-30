/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:49:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/31 03:07:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <algorithm>
# include <time.h>
# include <stdlib.h>
# include <fstream>

template <typename T, T v>
struct	integral_constant
{
	static const T	value = v;
	typedef T		value_type;
	operator value_type() const { return value; }
};

typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;

template <typename T>
struct	is_integer : false_type {};
template <>
struct	is_integer<int> : true_type {};

class Span
{
private:
	std::vector<int>	_array;
	unsigned int		_filled;

	template <typename Iterator>
	void	_wrap(true_type, Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) > std::distance(_array.begin() + _filled, _array.end()))
			throw SpanException();
		std::copy(begin, end, _array.begin() + _filled);
		_filled += std::distance(begin, end);
	}

	template <typename Iterator>
	void	_wrap(false_type, Iterator, Iterator)
	{
		throw (InvalidSpanTypeException());
	}

public:
	Span();
	Span(unsigned int N);
	Span(Span const & other);

	Span & operator=(Span const & other);

	~Span();

	void	addNumber(int number);

	int		shortestSpan(void);
	int		longestSpan(void);

	std::vector<int> const & getArray(void) const;

	/* Exceptions */
	class	SpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	InvalidSpanTypeException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	/* Templates */
	template <typename Iterator>
	void	fill(Iterator begin, Iterator end)
	{
		_wrap(is_integer<typename std::iterator_traits<Iterator>::value_type>(), begin, end);
	}

	void	fill(unsigned int N);
};

std::ostream & operator<<(std::ostream & o, Span const & span);

#endif