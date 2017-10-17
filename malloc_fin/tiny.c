/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:44:11 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 20:26:58 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				set_tinyheader(t_list *lst)
{
	int		i;

	i = 26;
	lst->content[25] = TRUE;
	while (i < 145)
	{
		lst->content[i] = FALSE;
		i++;
	}
	return (1);
}

int				one_place_atleasttiny(t_list *elem)
{
	int		i;

	i = 25;
	while (i < 145)
	{
		if (elem->content[i] == FALSE)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void			*another_tiny(size_t size)
{
	void	*str;
	int		f;
	t_list	*lst;
	t_list	*lst2;

	str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
		return (NULL);
	else
	{
		lst2 = browse_lst(g_zone.tiny);
		lst = ft_lstnew(str, PSIZE * 2);
		f = set_tinyheader(lst);
		lst2->next = lst;
		return (lst->content + 192);
	}
}

void			*already_tiny(size_t size)
{
	t_list		*lst;
	int			i;
	void		*str;

	i = 25;
	lst = ft_lstiter(g_zone.tiny, one_place_atleasttiny);
	if (lst == NULL)
	{
		str = another_tiny(size);
		return (str);
	}
	while (i < 145)
	{
		if (lst->content[i] == FALSE)
		{
			lst->content[i] = TRUE;
			return (lst->content + (192 + (64 * (i - 25))));
		}
		i++;
	}
	return (lst->content);
}

void			*first_tiny(size_t size)
{
	void	*str;
	int		f;

	str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
		return (NULL);
	else
	{
		g_zone.tiny = ft_lstnew(str, PSIZE * 2);
		f = set_tinyheader(g_zone.tiny);
		return (str + 192);
	}
}
