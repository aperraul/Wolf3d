/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:58:43 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/03 18:20:28 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp1;
	t_list	*temp2;

	if (*alst && alst && del)
	{
		temp1 = *alst;
		while (temp1->next)
		{
			temp2 = temp1->next;
			del(temp1->content, temp1->content_size);
			free(temp1);
			temp1 = temp2;
		}
		del(temp1->content, temp1->content_size);
		free(temp1);
		*alst = NULL;
	}
}
