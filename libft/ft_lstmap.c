/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:59:30 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 17:47:50 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*list;

	begin = NULL;
	if (lst && f)
	{
		list = f(lst);
		begin = list;
		while (lst->next)
		{
			list->next = f(lst->next);
			list = list->next;
			lst = lst->next;
		}
		list = f(lst);
	}
	return (begin);
}
