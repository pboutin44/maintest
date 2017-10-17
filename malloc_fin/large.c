/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:32:31 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 20:58:31 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*already_large(size_t size)
{
	void	*str;
	int		f;
	t_list	*lst;
	t_list	*lst2;
	int		nb;

	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
		return (NULL);
	else
	{
		lst2 = browse_lst(g_zone.large);
		lst = ft_lstnew(str, PSIZE * nb);
		lst2->next = lst;
		return (lst->content + 25);
	}
}

void		*first_large(size_t size)
{
	void	*str;
	int		f;
	int		nb;

	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
		return (NULL);
	else
	{
		g_zone.large = ft_lstnew(str, PSIZE * nb);
		return (str + 25);
	}
}
