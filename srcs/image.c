/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:32:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/24 20:51:44 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
il faut la fonction ft_draw
ft_draw_iso
*/






# define WIDTH 800
# define HEIGHT 500

typedef struct s_pixel {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}		t_pixel;

typedef struct s_point {
	int	x;
	int	y;
}		t_point;

void	calculate_image(t_pixel *draw)
{
	t_point *point1;
	t_point *point2;
	int		x;
	int		y;

	x = 0;
	// mettre une couleur de fond
	color_background(draw);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
		// récupérer les valeurs de x et y en utilisant t_pixel *point1.
		// tracer les lignes entre les deux points
			draw_lines(draw, point1, point2);
			y++;
		}
		x++;
	}
}

void color_background(t_pixel *draw)
{
	t_pixel color;
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			color.r = 255;
			// color.r = (double)x / WIDTH * 255;
			// color.g = (double)y / HEIGHT * 255;
			color.b = (double)x / WIDTH * 255;
			// color.b = 255;
			color.a = 0;
			draw[x + (y * WIDTH)] = color;
		}
	}
}

void draw_lines(t_pixel *draw, t_point *point1, t_point *point2)
{
	int	dx;
	int	dy;
	
	dx = abs(point2->x - point1->x);
	dy = abs(point2->y - point1->y);
	if (dx >= dy)
		x_is_the_star(dx, dy, point1, point2);
	else
		y_is_the_star(dx, dy, point1, point2);
}

void	x_is_the_star(int dx, int dy, t_point *point1, t_point *point2)
{
	int	error;

	error = 2 * dy - dx;
	ft_draw(point1->x, point1->y);
	while (point1->x < point2->x)
	{
		(point1->x)++;
		if (error < 0)
			error = error + 2 * dy;
		else
		{
			(point1->y)++;
			error = error + (2 * dy) - (2 * dx);
		}
		ft_draw(point1->x, point1->y);
	}
}

void	y_is_the_star(int dx, int dy, t_point *point1, t_point *point2)
{
	int	error;

	error = 2 * dx - dy;
	ft_draw(point1->x, point1->y);
	while (point1->y < point2->y)
	{
		(point1->y)++;
		if (error < 0)
			error = error + 2 * dx;
		else
		{
			(point1->x)++;
			error = error + (2 * dx) - (2 * dy);
		}
		ft_draw(point1->x, point1->y);
	}
}

void	ft_draw(t_point *pointx, t_point *pointy)
{
	
}
// 	int	error2;
// 	error = dx - dy;
	
// 	while (x1 != x2 && y1 != y2)
// 	{
// 		ft_draw(x1, y1);
// 		error2 = 2 * error;
// 		if (error2 > -dy)
// 		{
// 			error -= dy;
// 			if (x1 < x2)
// 				x1++;
// 			else
// 				x1--;
// 		}
// 		if (error2 < dx)
// 		{
// 			error += dx;
// 			if (y1 < y2)
// 				y1++;
// 			else
// 				y1--;
// 		}
// 	}
// 	ft_draw(x2, y2);
// }