/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/02/27 19:18:09 by tcherepoff       ###   ########.fr       */
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
