/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:39:21 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/28 20:30:51 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void    free_tiny1(void  *ptr, t_list    *lst, int   y)
{
	int     i;
	char    *str;

	i = 0;
	str = (char *)ptr;
	while(i < 64)
	{
		str[i] = 0;
		i++;
	}
	free2(lst, zone.tiny, 8192);
}


void    free2(t_list    *lst, t_list    *lst3, size_t size)
{
	t_list  *lst2;
	int     i;
	t_bool  flag;

	i = 0;
	flag = FALSE;
	if(lst != lst3)
	{
		while(i <= 100)
		{
			if(lst->content[i] == TRUE)
			{
				flag = TRUE;
			}
			i++;
		}
		if(flag == FALSE)
		{
			lst2 = find_browsesmall2(lst);
			lst2->next = lst->next;
			munmap(lst2->content, size);
		}
	}
}

void    free_small2(void     *ptr, t_list    *lst, int   y)
{
	int     i;
	char    *str;

	i = 0;
	str = (char *)ptr;
	while(i < 4096)
	{
		str[i] = 0;
		i++;
	}
	free2(lst, zone.small, PSIZE * 101);
}

void	free_small(void *ptr)
{
	t_list	*lst;
	int		j;
	int		i;


	lst = find_browsesmall(ptr);
	j = 4096;
	while(i < 126)
	{
		if(ptr == lst->content + j)
		{
			lst->content[i] = FALSE;
			free_small2(ptr, lst, i);
		}
		j = j + 4096;
		i++;
	}	
}

void		free_tiny(void	*ptr)
{
	t_list	*lst;
	int		j;
	int		i;

	lst = find_browsetiny(ptr);
	j = 192;
	i = 25;
	while(i < 145)
	{
		if(ptr == lst->content + j)
		{
			printf("ca ne marche pas");
			lst->content[i] = FALSE;
			free_tiny1(ptr, lst, i - 25);
		}
		j = j + 64;
		i++;
	}
}

void	ft_free(void *ptr)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 0;
	lst = find_browselarge(ptr);
	if(lst)
	{
		munmap(lst->content, lst->content_size);
	}
	else if(find_browsesmall(ptr))
	{
		free_small(ptr);
	}
	else if(find_browsetiny(ptr))
	{
		printf("free_tiny");
		free_tiny(ptr);
	}
}
