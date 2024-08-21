/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:15:10 by kdaniely          #+#    #+#             */
/*   Updated: 2024/08/21 16:26:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <stdint.h>
#include "Data.h"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);

	Serializer&	operator =(const Serializer& other);
	~Serializer();
public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif