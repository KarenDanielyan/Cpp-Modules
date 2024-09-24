/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:38:07 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/24 16:47:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(int ac, char **av)
{
	time_t	start;

	start = time(NULL);
	fill_container(_vbuf, ac, av);
	_vfill_time = time(NULL) - start;
	start = time(NULL);
	fill_container(_dbuf, ac, av);
	_dfill_time = time(NULL) - start;
}

PmergeMe::PmergeMe(const PmergeMe &other): _vbuf(other._vbuf), _dbuf(other._dbuf) {}

PmergeMe::PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vbuf = other._vbuf;
		_dbuf = other._dbuf;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

void	PmergeMe::sort(void)
{
	time_t	start;
	size_t	size;

	size = _vbuf.size();
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _vbuf.begin(); it != _vbuf.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	start = _getTime();
	_vsort();
	_vsort_time = _getTime() - start;
	start = _getTime();
	_dsort();
	_dsort_time = _getTime() - start;
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vbuf.begin(); it != _vbuf.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to fill vector of " << size << " elements: " << \
		_vfill_time << " us" << std::endl;
	std::cout << "Time to sort vector of " << size << " elements: " << \
		_vsort_time << " us" << std::endl;
	std::cout << "Time to fill deque of " << size << " elements: " << \
		_dfill_time << " us" << std::endl;
	std::cout << "Time to sort deque of " << size << " elements: " << \
		_dsort_time << " us" << std::endl;
}

void	PmergeMe::_vsort(void)
{
	std::sort(_vbuf.begin(), _vbuf.end());
}

void	PmergeMe::_dsort(void)
{
	std::sort(_dbuf.begin(), _dbuf.end());
}

/* Get time in ms. */
time_t	PmergeMe::_getTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((time_t)(tv.tv_sec * 1000000 + tv.tv_usec));

}