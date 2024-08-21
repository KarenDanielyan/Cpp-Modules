/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:47:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/22 03:19:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T>
void	decorate(T& item)
{
	std::cout << "Now [" << item << "] is decorated" << std::endl;
}

template <typename T>
void	iter(T* array, size_t size, void (*func)(T const &))
{
	for (size_t i = 0; i < size; i ++)
		func(array[i]);
}

#endif