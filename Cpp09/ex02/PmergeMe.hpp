/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:45:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/25 15:49:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <algorithm>
# include <sstream>
# include <iomanip>
# include <vector>
# include <deque>
# include <ctime>
# include <sys/time.h>
# include <cmath>

template <typename container>
void	fill_container(container &c, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		std::stringstream	ss(av[i]);
		int					n;

		ss >> n;
		c.push_back(n);
		i++;
	}
}

class PmergeMe
{
	private:
		std::vector<int>	_vbuf;
		std::deque<int>		_dbuf;

		time_t				_vfill_time;
		time_t				_dfill_time;
		time_t				_vsort_time;
		time_t				_dsort_time;

		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe&	operator=(const PmergeMe &other);

		time_t		_getTime(void);

		void		_vsort(void);
		void		_dsort(void);

		template <typename Container>
		void		_sort(Container &c);

		template <typename Container>
		void		_insert(Container &a, Container &b);

		template <typename Container>
		void		_inserion_sort(Container &c);
		
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe(void);

		void	sort(void);
};

template <typename Container>
void	PmergeMe::_inserion_sort(Container &c)
{
	for (size_t i = 1; i < c.size(); i++)
	{
		int	j = i;
		while (j > 0 && c[j - 1] > c[j])
		{
			std::swap(c[j - 1], c[j]);
			j--;
		}
	}
}

template <typename Container>
void	PmergeMe::_insert(Container &a, Container &b)
{
	size_t n = 0;
	size_t power = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < b.size();)
	{
		++power;

		n = pow(2, power) - n;

		start += n;

		end = start - n;

		if (start > b.size())
			start = b.size();

		for (size_t j = start - 1; j >= end;)
		{
			a.insert(std::upper_bound(a.begin(), a.end(), b[j]), b[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}

template <typename Container>
void	PmergeMe::_sort(Container &c)
{
	Container	a;
	Container	b;

	if (c.size() < 4)
	{
		_inserion_sort(c);
		return ;
	}
	for (size_t i = 0; i < c.size() / 2; i++)
	{
		int	_a = c[2 * i];
		int	_b = c[2 * i + 1];
		if (_a > _b)
		{
			a.push_back(_b);
			b.push_back(_a);
		}
		else
		{
			a.push_back(_a);
			b.push_back(_b);
		}
	}
	if (c.size() % 2 == 1)
		b.push_back(c[c.size() - 1]);
	_sort(a);
	_insert(a, b);
	c = a;
}

#endif