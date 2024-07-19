/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 18:45:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>
#include <cmath>

static Fixed	areaSquared(Point const &a, Point const &b, Point const &c)
{
	return (((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2));
}

static Fixed	abs(Fixed num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sABC = abs(areaSquared(a, b, c));
	Fixed	sPAB = abs(areaSquared(point, a, b));
	Fixed	sPBC = abs(areaSquared(point, b, c));
	Fixed	sPAC = abs(areaSquared(point, a, c));

	return (sABC == (sPAB + sPBC + sPAC));
}