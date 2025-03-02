/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:53:34 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/02 06:06:44 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_is_the_star(t_value *value, t_value point1, t_vom *vom)
{
	int	error;
	int	i;
	error = 2 * (abs(value->dy) - abs(value->dx));
	i = -1;
	while (++i < abs(value->dx))
	{
			if (value->dx < 0)
				point1.x--;
			else
				point1.x++;
			if (error < 0)
				error = error + 2 * abs(value->dy);
			else
			{
				if (value->dy < 0)
					point1.y -= 1;
				else
					point1.y += 1;
				error = error + (2 * abs(value->dy)) - (2 * abs(value->dx));
			}
			ft_put_pixel(vom, point1.x, point1.y, color(255, 0, 0));
	}
}

void	y_is_the_star(t_value *value, t_value point1, t_vom *vom)
{
	int	error;
	int	i;
	error = 2 * value->dx - value->dy;
	i = -1;
	while (++i < abs(value->dy))
	{
		if (value->dy < 0)
			point1.y -= 1;
		else
			point1.y += 1;
		if (error < 0)
			error = error + 2 * abs(value->dx);
		else
		{
			if (value->dx < 0)
				point1.x--;
			else
				point1.x++;
			error = error + 2 * (abs(value->dx) - abs(value->dy));
		}
		ft_put_pixel(vom, point1.x, point1.y, color(255, 0, 0));
	}
}
