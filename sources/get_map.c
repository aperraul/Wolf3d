/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:07:08 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/05 16:21:24 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static int **ft_fill_tab(t_lstline *list, int x)
{
	int		**tab;
	char	**str;
	int		i;
	int		j;
	int		k;
	int		*nb_x_line;

	nb_x_line = NULL;
	tab = NULL;
	tab = (int **)ft_memalloc(sizeof(int *) * (x + 1));
	nb_x_line = (int *)ft_memalloc(sizeof(int) * (x + 1));
	j = -1;
	while (++j < x)
	{
		str = ft_strsplit(list->line, ' ');
		nb_x_line[j] = ft_memlen((void **)str);
		tab[j] = (int *)ft_memalloc(sizeof(int) * (nb_x_line[j] + 1));
		i = -1;
		while (str[++i])
			tab[j][i] = ft_atoi(str[i]);
		k = -1;
		while (str[++k])
			ft_memdel((void **)&str[k]);
		ft_memdel((void **)&str);
		list = list->next;
	}
	return (tab);
}

void		ft_get_map(t_w3d *w3d, int ret)
{
	int			nb_lines;
	char		*line;
	t_lstline	*list;

	line = NULL;
	list = NULL;
	nb_lines = 0;
	while (get_next_line(ret, &line) > 0)
	{
		list = ft_add_list(list, line);
		nb_lines++;
	}
	w3d->map = ft_fill_tab(list, nb_lines);
}
