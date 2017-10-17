/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:36:06 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 20:56:23 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list				*find_browselarge(void *ptr)
{
	t_list		*tmp;

	tmp = g_zone.large;
	while (tmp)
	{
		if (tmp->content + 25 == ptr)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_list				*find_browsetiny(void *ptr)
{
	t_list	*tmp;
	int		i;

	i = 25;
	tmp = g_zone.tiny;
	while (tmp)
	{
		if (tmp->content <= (char *)ptr && tmp->content +
				2 * PSIZE >= (char *)ptr)
		{
			while (i < 145)
			{
				if (tmp->content + (192 + (64 * (i - 25))) == ptr)
					return (tmp);
				i++;
			}
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_list				*find_browsesmall2(t_list *lst)
{
	t_list	*tmp;

	tmp = g_zone.small;
	while (tmp)
	{
		if (tmp->next == lst)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_list				*find_browsesmall(void *ptr)
{
	t_list	*tmp;
	int		i;

	i = 25;
	tmp = g_zone.small;
	while (tmp)
	{
		if (tmp->content <= (char *)ptr && tmp->content + 26 *
				PSIZE >= (char *)ptr)
		{
			while (i < 129)
			{
				if (tmp->content + (1023 + (1024 * (i - 25))) == ptr)
					return (tmp);
				else
					return (NULL);
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (NULL);
}
