/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:45:41 by kdaniely          #+#    #+#             */
/*   Updated: 2024/09/24 16:42:33 by kdaniely         ###   ########.fr       */
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
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe(void);

		void	sort(void);
};

#endif