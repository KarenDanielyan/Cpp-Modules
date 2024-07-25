/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:38:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/07/25 15:29:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.h"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const Point &other);
		Point(const float x, const float y);

		~Point();

		Point	&operator=(const Point &other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream	&operator<<(std::ostream &out, Point const &self);

bool			bsp(Point const a, Point const b, Point const c, \
					Point const point);

#endif
