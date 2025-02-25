/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:56:42 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/25 02:26:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define WIDTH 800
# define HEIGHT 500

typedef struct s_pixel {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}		t_pixel;


int keyPress(int key, void *mlx)
{
	if (key == 65307)
		mlx_loop_end(mlx);
	return (1);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int trash;
	char	**tab;

	if (ac == 2)
	{
		// Parsing
		tab = ft_parsing(av);
		if (tab == NULL)
			ft_putstr_fd("Il y a un probleme la !!! \n", 2);

		// Init
		void *mlx = mlx_init();
		void *window = mlx_new_window(mlx, WIDTH, HEIGHT, "<Insert Title>");
		void *img = mlx_new_image(mlx, WIDTH, HEIGHT);
		t_pixel *draw = (t_pixel *)mlx_get_data_addr(img, &trash, &trash, &trash);
		mlx_key_hook(window, keyPress, mlx);
		mlx_hook(window, 33, 1L << 17, mlx_loop_end, mlx);

		// calculer les points
		calculate_image(draw);
		mlx_put_image_to_window(mlx, window, img, 0, 0);

		mlx_loop(mlx);

		// free
		mlx_destroy_image(mlx, img);
		mlx_destroy_window(mlx, window);
		mlx_destroy_display(mlx);
		free(mlx);
	}
	else
		ft_putstr_fd("Il y a un probleme la !!! \n", 2);
	}
	*/


int	ft_create_image(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (-1);
	return (1);
}
