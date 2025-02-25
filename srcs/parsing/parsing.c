/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:52:28 by ltcherep          #+#    #+#             */
/*   Updated: 2025/02/25 05:10:48 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	ft_create_element(int value_element, t_list **new_element)
{
	(*new_element) = malloc(sizeof(t_list));
	if (!(*new_element))
		return (-1);
	(*new_element)->content = value_element;
	(*new_element)->next = NULL;
	return (1);
}

int	ft_add_the_element(t_list **list, int value_element)
{
	t_list	*new_element;
	t_list	*tmp;
	
	if (ft_create_element(value_element, &new_element) == -1)
		return (-1);
	if (!(*list))
		(*list) = new_element;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_element;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	int		v;
	int		z;
	int		**tab;
	int		size_line;
	int		nb_line;
	char	*line;
	char	**bb;
	t_list	*list;
	t_list	*current;
	
	size_line = 1;
	i = 0;
	v = 1;
	list = NULL;

	// ouvrir le fichier 
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	
	// récupérer les lignes
	while ((line = get_next_line(fd)))
	{
		bb = ft_split(line, ' ');
		
		free(line);
		i = 0;
		while (bb[i] != NULL)
		{
			ft_add_the_element(&list, ft_atoi(bb[i]));
			i++;
		}
		i = 0;
		if (v)
		{
			while (bb[++i] != NULL)
				size_line++;
			v = 0;
		}
		while (bb[i])
		{
			free(bb[i]);
			i++;
		}
		free(bb);
	}
	close(fd);
	nb_line = ft_lstsize(list) / size_line;
	current = list;
	tab = malloc(sizeof(int *) * ft_lstsize(list) + 1);
	i = 0;
	while (i < nb_line)
	{
		z = 0;
		tab[i] = malloc(sizeof(int) * size_line);
		while (current && z < size_line)
		{
			tab[i][z] = current->content;
			current = current->next;
			z++;
		}
		i++;
	}
	return (0);
}
