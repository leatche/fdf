/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:56:42 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/20 01:36:05 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_parsing(av[1]);
		if (tab == -1)
			ft_putstr_fd("Il y a un probleme la !!! \n", 2);

	}
	else
		ft_putstr_fd("Il y a un probleme la !!! \n", 2);
}

int	ft_create_image(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (-1);
	
}
