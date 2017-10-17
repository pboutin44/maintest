/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:39:21 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 21:11:28 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free_tiny1(void *ptr, t_list *lst, int y)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < 64)
	{
		str[i] = 0;
		i++;
	}
	free2(lst, g_zone.tiny, 8192);
}

int				free2(t_list *lst, t_list *lst3, size_t size)
{
	t_list	*lst2;
	int		i;
	t_bool	flag;

	i = 25;
	flag = FALSE;
	if (lst != lst3)
	{
		while (i <= 129)
		{
			if (lst->content[i] == TRUE)
			{
				flag = TRUE;
			}
			i++;
		}
		if (flag == FALSE)
		{
			lst2 = find_browsesmall2(lst);
			lst2->next = lst->next;
			munmap(lst2->content, size);
		}
	}
	return (1);
}

int				free_small2(void *ptr, t_list *lst, int y)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < 1024)
	{
		str[i] = 0;
		i++;
	}
	free2(lst, g_zone.small, PSIZE * 26);
	return (0);
}

void			free_small(void *ptr)
{
	t_list	*lst;
	int		j;
	int		i;
	int		v;

	v = 0;
	lst = find_browsesmall(ptr);
	i = 25;
	if (lst)
	{
		j = 1023;
		while (i < 129)
		{
			if (ptr == lst->content + (j + ((i - 25) * 1024)))
			{
				lst->content[i] = FALSE;
				v = free_small2(ptr, lst, i);
			}
			if (v == 1)
				break ;
			i++;
		}
	}
}

void			free_tiny(void *ptr)
{
	t_list	*lst;
	int		j;
	int		i;

	lst = find_browsetiny(ptr);
	j = 192;
	i = 25;
	while (i < 145)
	{
		if (ptr == lst->content + j)
		{
			lst->content[i] = FALSE;
			free_tiny1(ptr, lst, i - 25);
		}
		j = j + 64;
		i++;
	}
}
