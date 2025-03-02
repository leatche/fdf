/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:53:34 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/02 05:58:30 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_is_the_star(t_value *value, t_value point1, t_vom *vom)
{
	printf(" x\n");
	int	error;
	int	i;
	//int	depend_y;
	//int	depend_x;

	// // if (point1.x < vom->size_line)
	// depend_x = -1;
	// // else
	// // 	depend_x = -1;
	// if (point1.y < vom->nb_line)
	// 	depend_y = -1;
	// else
	// 	depend_y = 1;
	error = 2 * (abs(value->dy) - abs(value->dx));
	i = -1;
	// printf("depend yx : %d\n", depend_y);
	// //printf("depend xx : %d\n", depend_x);
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
	printf(" y\n");
	// int	depend_x;
	// int	depend_y;

	// if (point1.y < vom->nb_line)
	// 	depend_y = 1;
	// else
	// 	depend_y = -1;
	// if (point1.x < vom->size_line)
	// 	depend_x = -1;
	// else
	// 	depend_x = 1;
	// printf("depend yy : %d", depend_y);
	// printf("depend xy : %d", depend_x);
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