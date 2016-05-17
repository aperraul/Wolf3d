/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:07:08 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/17 11:46:06 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

static void		ft_fill_tab(t_lstline *list, int x, t_w3d *w3d)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	w3d->map = (int **)ft_memalloc(sizeof(int *) * (x + 1));
	w3d->nb_x_line = (int *)ft_memalloc(sizeof(int) * (x + 1));
	j = -1;
	while (++j < x)
	{
		str = ft_strsplit(list->line, ' ');
		w3d->nb_x_line[j] = ft_memlen((void **)str);
		w3d->map[j] = (int *)ft_memalloc(sizeof(int) * (w3d->nb_x_line[j] + 1));
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

static void		ft_line_error(t_lstline *list, t_w3d *w3d)
{
	if (list != NULL)
		ft_lstline_del(list);
	if (w3d->nb_spawn < 1)
		ft_putstr("error: no spawn set\n");
	ft_putstr("error: invalid map\n");
	w3d->map = NULL;
	return ;
}

static void		ft_fill_lst(t_w3d *w3d, int ret, t_lstline **list)
{
	char	*line;

	while (get_next_line(ret, &line) > 0)
	{
		if (ft_check_line(line, w3d) == 0)
		{
			ft_line_error(*list, w3d);
			return ;
		}
		*list = ft_add_list(*list, line);
		w3d->nb_lines++;
	}
}

void			ft_get_map(t_w3d *w3d, int ret)
{
	t_lstline	*list;
	int			error;

	list = NULL;
	ft_fill_lst(w3d, ret, &list);
	if (w3d->nb_lines < 3 || w3d->nb_spawn < 1)
	{
		ft_line_error(list, w3d);
		return ;
	}
	ft_fill_tab(list, w3d->nb_lines, w3d);
	if ((error = ft_check_map(w3d)) != 0)
	{
		ft_line_error(list, w3d);
		ft_putstr("error: ");
		ft_putnbr(error);
		ft_putstr(" error on the map\n");
		return ;
	}
	ft_lstline_del(list);
}
