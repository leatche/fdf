/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:56:42 by ltcherep          #+#    #+#             */
/*   Updated: 2025/03/02 02:50:27 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	ft_parsing(vom, av[1]);
	if (vom->tab == NULL)
	{
		ft_putstr_fd("Il y a un probleme la !!! \n", 2);
		return (1);
	}
	ft_init(vom);
	calculate_image(vom);
	mlx_put_image_to_window(vom->mlx, vom->window, vom->img, 0, 0);
	mlx_loop(vom->mlx);
	mlx_destroy_image(vom->mlx, vom->img);
	mlx_destroy_window(vom->mlx, vom->window);
	mlx_destroy_display(vom->mlx);
	free_tab((void **)vom->tab);
	free(vom->mlx);
	free(vom);
}

void	ft_init(t_vom *vom)
{
	int	t;

	vom->mlx = mlx_init();
	vom->window = mlx_new_window(vom->mlx, WIDTH, HEIGHT, "Cute Page");
	vom->img = mlx_new_image(vom->mlx, WIDTH, HEIGHT);
	vom->draw = (t_pixel *)mlx_get_data_addr(vom->img, &t, &t, &t);
	mlx_key_hook(vom->window, key_press, vom->mlx);
	mlx_hook(vom->window, 33, 1L << 17, mlx_loop_end, vom->mlx);
}
