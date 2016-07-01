/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:46:30 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 11:42:27 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		delfree(t_list *list, void (*del)(void *, size_t))
{
	del(list->content, list->content_size);
	free(list);
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;
	int		flag;

	tmp = *alst;
	flag = 0;
	tmp2 = NULL;
	if (tmp->next)
	{
		tmp2 = tmp->next;
		flag = 1;
	}
	while (tmp2->next)
	{
		delfree(tmp, del);
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	del(tmp->content, tmp->content_size);
	free(tmp);
	if (flag == 1)
		delfree(tmp2, del);
	*alst = NULL;
}
