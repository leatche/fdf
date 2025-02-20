/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:52:28 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/20 00:20:14 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_parsing(char **av)
{
	char	**tab;
	char	*line;
	int		fd
	int		i;

	i = 0;
	fd = open(av[1]);
	if (fd == -1)
		return (-1);
	while (line = ft_get_next_line(fd) != NULL)
	{
		tab[i] = ft_split(line, ' ');
		i++;
		free (line);
	}
	tab[i] = '\0';
	close(fd);
	return (tab);
}
