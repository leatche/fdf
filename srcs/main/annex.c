/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/04 00:25:34 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, void *mlx)
{
	if (key == 65307)
		mlx_loop_end(mlx);
	return (1);
}

int	ft_create_image(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (-1);
	return (1);
}

void	free_vom(t_vom *vom)
{
	mlx_destroy_image(vom->mlx, vom->img);
	mlx_destroy_window(vom->mlx, vom->window);
	mlx_destroy_display(vom->mlx);
	free_tab((void **)vom->tab);
	free(vom->mlx);
	free(vom);
}

void	ft_init_minmax(t_vom *vom)
{
	vom->min.x = vom->width;
	vom->max.x = 0;
	vom->min.y = vom->height;
	vom->max.y = 0;
}
