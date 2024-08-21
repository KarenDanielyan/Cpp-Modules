/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:30:57 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/22 02:33:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

template <typename T>
void	swap(T& A, T&B)
{
	T	temp;

	temp = A;
	A = B;
	B = temp;
}

template <typename T>
T	min(T& A, T&B)
{
	return ((A < B ? A : B));
}

template <typename T>
T	max(T& A, T& B)
{
	return ((A > B ? A : B));
}

#endif