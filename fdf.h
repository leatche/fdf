/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:34:14 by ltcherep          #+#    #+#             */
/*   Updated: 2025/03/04 00:28:09 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define OFFSET 250
# define TITLE "Cute Page"

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_pixel {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}		t_pixel;

typedef struct s_value {
	int	x;
	int	y;
	int	dx;
	int	dy;
}		t_value;

typedef struct s_vom {
	int		size_line;
	int		nb_line;
	int		**tab;
	double	size;
	int		height;
	int		width;
	t_value	min;
	t_value	max;
	t_value	offset;
	void	*mlx;
	void	*window;
	void	*img;
	t_pixel	*draw;
}		t_vom;

void	ft_init(t_vom *vom);

void	ft_parsing(t_vom *vom, char *file_name);
t_list	*ft_put_in_list(t_vom *vom, char *file_name);

int		*ft_alloc_number(int n);
void	free_tab(void **tab);

t_pixel	color(int r, int g, int b);
void	color_background(t_vom *vom);
int		iso_x(int x, int y);
int		iso_y(int x, int y, int z);
t_value	point(int x, int y);

void	x_is_the_star(t_value *value, t_value point1, t_vom *vom);
void	y_is_the_star(t_value *value, t_value point1, t_vom *vom);

void	ft_put_pixel(t_vom *vom, int x, int y, t_pixel color);
void	draw_lines(t_vom *vom, t_value	*value, t_value point1, t_value point2);
void	calculate_image(t_vom *vom);

int		key_press(int key, void *mlx);
int		ft_create_image(void);
void	ft_init_minmax(t_vom *vom);
void	free_vom(t_vom *vom);

#endif
