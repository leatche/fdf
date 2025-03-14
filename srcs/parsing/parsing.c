/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:52:28 by ltcherep          #+#    #+#             */
/*   Updated: 2025/03/04 00:50:12 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen_char(char **bb)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	if (!bb || !*bb)
		return (-1);
	while (bb[i] != NULL)
	{
		size++;
		i++;
	}
	return (size);
}

int	add_line_to_list(t_vom *vom, t_list **list, char *line)
{
	char	**bb;
	int		i;

	bb = ft_split(line, ' ');
	free(line);
	if (*list == NULL)
		vom->size_line = ft_strlen_char(bb);
	i = 0;
	if (!bb || !*bb)
		return (1);
	while (bb[i] != NULL)
	{
		ft_lstadd_back(list, ft_lstnew(ft_alloc_number(ft_atoi(bb[i]))));
		i++;
	}
	free_tab((void *)bb);
	return (0);
}

t_list	*ft_put_in_list(t_vom *vom, char *file_name)
{
	t_list	*list;
	char	*line;
	int		fd;

	list = NULL;
	line = "";
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (add_line_to_list(vom, &list, line))
			return (NULL);
	}
	close(fd);
	return (list);
}

int	ft_parsing(t_vom *vom, char *file_name)
{
	int		i;
	int		z;
	t_list	*list;
	t_list	*current;

	list = ft_put_in_list(vom, file_name);
	if (!list)
		return (1);
	vom->nb_line = ft_lstsize(list) / vom->size_line;
	current = list;
	vom->tab = ft_calloc(sizeof(int *), (ft_lstsize(list) + 1));
	i = -1;
	while (++i < vom->nb_line)
	{
		z = -1;
		vom->tab[i] = malloc(sizeof(int) * vom->size_line);
		while (current && ++z < vom->size_line)
		{
			vom->tab[i][z] = *((int *)current->content);
			current = current->next;
		}
	}
	ft_lstclear(&list, free);
	return (0);
}
