/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:02:12 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/19 18:07:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

Point::Point(): x(0), y(0) {}

Point::Point(const Point &other): x(other.x), y(other.y) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::~Point() {}

Point	&Point::operator=(Point const &other)
{
	(void)other;
	return (*this);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &out, Point const &self)
{
	out << self.getX() << " " << self.getY();
	return (out);
}