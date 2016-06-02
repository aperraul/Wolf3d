/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:11:03 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/02 14:34:49 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstline_del(t_lstline *alst)
{
	t_lstline	*temp1;
	t_lstline	*temp2;

	if (alst)
	{
		temp1 = alst;
		while (temp1->next)
		{
			temp2 = temp1->next;
			ft_memdel((void **)&temp1->line);
			ft_memdel((void **)&temp1);
			temp1 = temp2;
		}
		ft_memdel((void **)&temp1->line);
		ft_memdel((void **)&temp1);
		alst = NULL;
	}
}

t_lstline	*ft_next_list(void)
{
	t_lstline	*list;

	list = (t_lstline *)malloc(sizeof(t_lstline));
	list->next = NULL;
	list->line = NULL;
	return (list);
}

t_lstline	*ft_add_list(t_lstline *begin, char *line)
{
	t_lstline	*list;

	if (!(begin))
	{
		begin = ft_next_list();
		begin->line = line;
		return (begin);
	}
	list = begin;
	while (list->next)
		list = list->next;
	list->next = ft_next_list();
	list = list->next;
	list->line = line;
	return (begin);
}
