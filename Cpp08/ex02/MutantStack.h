/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 03:26:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/31 16:55:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {};
	MutantStack<T>&	operator=(const MutantStack<T>& other);

	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator	\
		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	\
		const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	\
		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	\
		const_reverse_iterator;
	
	iterator	begin() {return (this->c.begin());}
	iterator	end() {return (this->c.end());}
	const_iterator	begin() const {return (this->c.begin());}
	const_iterator	end() const {return (this->c.end());}
	reverse_iterator	rbegin() {return (this->c.rbegin());}
	reverse_iterator	rend() {return (this->c.rend());}
	const_reverse_iterator	rbegin() const {return (this->c.rbegin());}
	const_reverse_iterator	rend() const {return (this->c.rend());}
};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
}

#endif