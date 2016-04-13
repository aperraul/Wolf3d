/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:07:08 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/13 11:49:19 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Header.h"

static void		ft_fill_tab(t_lstline *list, int x, t_w3d *w3d)
{
	char	**str;
	int		i;
	int		j;
	int		k;
	int		*nb_x_line;

	w3d->map = (int **)ft_memalloc(sizeof(int *) * (x + 1));
	nb_x_line = (int *)ft_memalloc(sizeof(int) * (x + 1));
	j = -1;
	while (++j < x)
	{
		str = ft_strsplit(list->line, ' ');
		nb_x_line[j] = ft_memlen((void **)str);
		w3d->map[j] = (int *)ft_memalloc(sizeof(int) * (nb_x_line[j] + 1));
		i = -1;
		while (str[++i])
			w3d->map[j][i] = ft_atoi(str[i]);
		k = -1;
		while (str[++k])
			ft_memdel((void **)&str[k]);
		ft_memdel((void **)&str);
		list = list->next;
	}
}

void			ft_get_map(t_w3d *w3d, int ret)
{
	char		*line;
	t_lstline	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(ret, &line) > 0)
	{
		if (ft_check_line(line) == 0)
		{
			w3d->map = NULL;
			return ;
		}
		list = ft_add_list(list, line);
		w3d->nb_lines++;
	}
	ft_fill_tab(list, w3d->nb_lines, w3d);
	ft_lstline_del(list);
}
