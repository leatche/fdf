/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:43:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/28 19:21:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	color(int r, int g, int b)
{
	t_pixel	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	color_background(t_pixel *draw)
{
	t_pixel	color;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color.r = (double)x / WIDTH * 255;
			color.b = 200;
			color.a = 0;
			draw[x + (y * WIDTH)] = color;
			y++;
		}
		x++;
	}
}

int	iso_x(int x, int y)
{
	return (x - y);
}

int	iso_y(int x, int y, int z)
{
	return ((x + y) / 2 - z);
}

t_value	point(int x, int y)
{
	t_value	dest;

	dest.x = x;
	dest.y = y;
	return (dest);
}
