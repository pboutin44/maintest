/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:08:45 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 21:10:09 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free(void *ptr)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 0;
	lst = find_browselarge(ptr);
	if (lst)
	{
		munmap(lst->content, lst->content_size);
		g_zone.large = NULL;
	}
	else if (find_browsesmall(ptr))
		free_small(ptr);
	else if (find_browsetiny(ptr))
		free_tiny(ptr);
}
