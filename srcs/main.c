/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:56:42 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/22 15:05:59 by tcherepoff       ###   ########.fr       */
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

void calculate_image(t_pixel *draw)
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

int keyPress(int key, void *mlx)
{
	if (key == 65307)
		mlx_loop_end(mlx);
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int trash;
	// Parsing

	// Init
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, WIDTH, HEIGHT, "<Insert Title>");
	void *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	t_pixel *draw = (t_pixel *)mlx_get_data_addr(img, &trash, &trash, &trash);
	mlx_key_hook(window, keyPress, mlx);
	mlx_hook(window, 33, 1L << 17, mlx_loop_end, mlx);

	calculate_image(draw);	
	mlx_put_image_to_window(mlx, window, img, 0, 0);

	mlx_loop(mlx);

	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
	// char	**tab;

	// if (ac == 2)
	// {
	// 	tab = ft_parsing(av);
	// 	if (tab == NULL)
	// 		ft_putstr_fd("Il y a un probleme la !!! \n", 2);

	// }
	// else
	// 	ft_putstr_fd("Il y a un probleme la !!! \n", 2);
}

int	ft_create_image(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (-1);
	return (1);
}
