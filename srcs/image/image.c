/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:32:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/02 06:18:11 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_vom *vom, int x, int y, t_pixel color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	vom->draw[x + (y * WIDTH)] = color;
}

void	draw_lines(t_vom *vom, t_value *value, t_value point1, t_value point2)
{
	value->dx = point2.x - point1.x;
	value->dy = point2.y - point1.y;
	if (abs(value->dx) > abs(value->dy))
		x_is_the_star(value, point1, vom);
	else
		y_is_the_star(value, point1, vom);
}

#define SIZE 7

void	calculate_image(t_vom *vom)
{
	t_value	*value;
	t_value point1;
	t_value point2;
	int		x;
	int		y;
	int		z;

	y = 0;
	value = (t_value*)malloc(sizeof(t_value));
	// color_background(vom->draw);
	while (y < vom->nb_line - 1)
	{
		x = 0;
		while (x < vom->size_line - 1)
		{
			z = vom->tab[y][x];
			ft_put_pixel(vom, 250 + iso_x(x * SIZE, y * SIZE), 250 + iso_y(x * SIZE, y * SIZE, z * SIZE), color(0, 0, 0));
			point1.x = 250 + iso_x(x * SIZE, y * SIZE);
			point1.y = 250 + iso_y(x * SIZE, y * SIZE, (vom->tab[y][x] / 5) * SIZE);
			point2.x = 250 + iso_x((x + 1) * SIZE, y * SIZE);
			point2.y = 250 + iso_y((x + 1) * SIZE, y * SIZE, (vom->tab[y][x + 1] / 5) * SIZE);
			draw_lines(vom, value, point(point1.x, point1.y), point(point2.x, point2.y));
			point2.x = 250 + iso_x(x * SIZE, (y + 1) * SIZE);
			point2.y = 250 + iso_y(x * SIZE, (y + 1) * SIZE, (vom->tab[y + 1][x] / 5) * SIZE);
			draw_lines(vom, value, point(point1.x, point1.y), point(point2.x, point2.y));
			x++;
		}
		y++;
	}
	// draw_lines(vom, value, point(WIDTH / 2, HEIGHT / 2), point(0, 0));
	// draw_lines(vom, value, point(WIDTH / 2, HEIGHT / 2), point(WIDTH, 0));
	// draw_lines(vom, value, point(WIDTH / 2, HEIGHT / 2), point(0, HEIGHT));
	// draw_lines(vom, value, point(WIDTH / 2, HEIGHT / 2), point(WIDTH, HEIGHT));
	free(value);
}
