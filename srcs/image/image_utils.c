/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:43:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/04 01:16:38 by tcherepoff       ###   ########.fr       */
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

void	color_background(t_vom *vom)
{
	t_pixel	color;
	int		x;
	int		y;

	x = 0;
	while (x < vom->width)
	{
		y = 0;
		while (y < vom->height)
		{
			color.r = (double)x / vom->width * 255;
			color.b = 200;
			color.a = 0;
			if (vom->draw[x + (y * vom->width)].r == 255)
				vom->draw[x + (y * vom->width)] = color;
			y++;
		}
		x++;
	}
}

double	iso_x(int x, int y)
{
	return (x - y);
}

double	iso_y(int x, int y, int z)
{
	return ((double)(x + y) / 2 - ((double)z / 5));
}

t_value	point(int x, int y)
{
	t_value	dest;

	dest.x = x;
	dest.y = y;
	return (dest);
}
