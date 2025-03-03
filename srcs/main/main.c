/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:56:42 by ltcherep          #+#    #+#             */
/*   Updated: 2025/03/04 00:24:59 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_border(t_vom *vom)
{
	int		x;
	int		y;
	t_value	iso;

	y = 0;
	while (y < vom->nb_line)
	{
		x = 0;
		while (x < vom->size_line)
		{
			iso.x = iso_x(x, y) * vom->size;
			iso.y = iso_y(x, y, vom->tab[y][x] / 5) * vom->size;
			if (iso.x < vom->min.x)
				vom->min.x = iso.x;
			if (iso.x > vom->max.x)
				vom->max.x = iso.x;
			if (iso.y < vom->min.y)
				vom->min.y = iso.y;
			if (iso.y > vom->max.y)
				vom->max.y = iso.y;
			x++;
		}
		y++;
	}
}

void	ft_calculate_border(t_vom *vom)
{
	t_value	offset;

	offset.x = INT_MAX;
	offset.y = INT_MAX;
	ft_init_minmax(vom);
	ft_get_border(vom);
	vom->size = 1;
	while (offset.x > OFFSET && offset.y > OFFSET)
	{
		offset.x = (vom->width - (vom->size * (vom->max.x - vom->min.x))) / 2;
		offset.y = (vom->height - (vom->size * (vom->max.y - vom->min.y))) / 2;
		vom->size++;
	}
	while (offset.x < OFFSET && offset.y < OFFSET)
	{
		offset.x = (vom->width - (vom->size * (vom->max.x - vom->min.x))) / 2;
		offset.y = (vom->height - (vom->size * (vom->max.y - vom->min.y))) / 2;
		vom->size -= 0.01;
	}
	vom->size += 0.01;
}

int	main(int ac, char **av)
{
	t_vom	*vom;
	int		i;

	i = 0;
	while (av[i])
		i++;
	if (ac != 2)
	{
		ft_putstr_fd("Il y a un probleme la !!! \n", 2);
		return (1);
	}
	vom = malloc(sizeof(t_vom));
	vom->size = 1;
	ft_parsing(vom, av[1]);
	if (vom->tab == NULL)
	{
		ft_putstr_fd("Il y a un probleme la !!! \n", 2);
		return (1);
	}
	ft_init(vom);
	ft_calculate_border(vom);
	calculate_image(vom);
	mlx_put_image_to_window(vom->mlx, vom->window, vom->img, 0, 0);
	mlx_loop(vom->mlx);
	free_vom(vom);
}

void	ft_init(t_vom *vom)
{
	int	t;

	vom->mlx = mlx_init();
	mlx_get_screen_size(vom->mlx, &vom->width, &vom->height);
	vom->width -= 100;
	vom->height -= 100;
	vom->window = mlx_new_window(vom->mlx, vom->width, vom->height, TITLE);
	vom->img = mlx_new_image(vom->mlx, vom->width, vom->height);
	vom->draw = (t_pixel *)mlx_get_data_addr(vom->img, &t, &t, &t);
	mlx_key_hook(vom->window, key_press, vom->mlx);
	mlx_hook(vom->window, 33, 1L << 17, mlx_loop_end, vom->mlx);
}
