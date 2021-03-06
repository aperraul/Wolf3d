/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:07:08 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/08 12:17:13 by aperraul         ###   ########.fr       */
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

static void		ft_line_error(t_lstline *list, t_w3d *w3d, int mode)
{
	if (list != NULL)
		ft_lstline_del(list);
	if (mode == 1)
		ft_putstr("error: invalid line\n");
	if (mode == 2)
	{
		if (w3d->nb_lines < 3)
			ft_putstr("error: less than 3 lines\n");
		if (w3d->nb_spawn < 1)
			ft_putstr("error: no spawn 's' set\n");
	}
	if (mode > 2)
	{
		ft_putstr("error: ");
		ft_putnbr(mode - 2);
		ft_putstr(" error on the map\n");
		ft_del_map(w3d);
	}
	w3d->map = NULL;
	exit(0);
}

static void		ft_fill_lst(t_w3d *w3d, int ret, t_lstline **list)
{
	char	*line;

	line = NULL;
	while (get_next_line(ret, &line) > 0)
	{
		if (ft_check_line(line, w3d) == 0)
			ft_line_error(*list, w3d, 1);
		*list = ft_add_list(*list, line);
		w3d->nb_lines++;
	}
	free(line);
}

void			ft_get_map(t_w3d *w3d, int ret)
{
	t_lstline	*list;
	int			error;

	list = NULL;
	ft_fill_lst(w3d, ret, &list);
	if (w3d->nb_lines < 3 || w3d->nb_spawn < 1)
		ft_line_error(list, w3d, 2);
	ft_fill_tab(list, w3d->nb_lines, w3d);
	if ((error = ft_check_map(w3d)) != 0)
		ft_line_error(list, w3d, (error + 2));
	ft_lstline_del(list);
}
