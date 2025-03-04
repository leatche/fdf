/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:32:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/04 01:14:20 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_vom *vom, int x, int y, t_pixel color)
{
	if (x < 0 || x >= vom->width || y < 0 || y >= vom->height)
		return ;
	vom->draw[x + (y * vom->width)] = color;
}

void	draw_line(t_vom *vom, t_value *value, t_value point1, t_value point2)
{
	value->dx = point2.x - point1.x;
	value->dy = point2.y - point1.y;
	if (abs(value->dx) > abs(value->dy))
		x_is_the_star(value, point1, vom);
	else
		y_is_the_star(value, point1, vom);
}

t_value	to_iso(t_vom *vom, int x, int y)
{
	t_value	dest;
	t_value	draw_size;

	draw_size.x = vom->size * (vom->max.x - vom->min.x);
	draw_size.y = vom->size * (vom->max.y - vom->min.y);
	dest.x = -(vom->min.x * vom->size) + iso_x(x, y) * vom->size
		+ (vom->width - draw_size.x) / 2;
	dest.y = -(vom->min.y * vom->size) + iso_y(x, y, vom->tab[y][x]) * vom->size
		+ (vom->height - draw_size.y) / 2;
	return (dest);
}

void	calculate_image(t_vom *vom)
{
	t_value	*value;
	int		x;
	int		y;

	y = 0;
	value = (t_value *)malloc(sizeof(t_value));
	while (y < vom->nb_line)
	{
		x = 0;
		while (x < vom->size_line)
		{
			if (x < vom->size_line - 1)
				draw_line(vom, value, to_iso(vom, x, y), to_iso(vom, x + 1, y));
			if (y < vom->nb_line - 1)
				draw_line(vom, value, to_iso(vom, x, y), to_iso(vom, x, y + 1));
			x++;
		}
		y++;
	}
	color_background(vom);
	free(value);
}
