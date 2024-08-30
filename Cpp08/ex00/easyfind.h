/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:16:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/30 18:34:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EAASYFIND_H

# include <algorithm>
# include <stdexcept>

/**
 * @brief	easyfind<T> function takes a container and a location \
 * 			returns an iterator to the location if found,
 * 			else throws out_of_range exception.
 * 
 * @param container		Container to search.
 * @param loc			Location to search for.
 * @return T::iterator	An iterator to the location if found.
 */
template <typename T>
typename T::iterator easyfind(T& container, int loc)
{
	typename T::iterator	it;
	
	it = std::find(container.begin(), container.end(), loc);
	if (it == container.end())
		throw (std::out_of_range("Element not found"));
	return (it);
}

#endif