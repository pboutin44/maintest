/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:44:11 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/16 14:00:13 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int     set_tinyheader(t_list  *lst)
{
	int     i;

	i = 26;
	lst->content[25] = TRUE;
	while(i < 145)
	{
		lst->content[i] = FALSE;
		i++;
	}
	return(1);
}

int     one_place_atleasttiny(t_list   *elem)
{
	int		i;

	i = 25;
	while(i < 145)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

void    *another_tiny(size_t size)
{
    void    *str;
    int     f;
    t_list  *lst;
    t_list  *lst2;
	//printf("TINY");
    str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        //printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.tiny);
        lst = ft_lstnew(str, PSIZE * 2);
        f = set_tinyheader(lst);
        lst2->next = lst;
        return(lst->content + 192);
    }
}

void		*already_tiny(size_t size)
{
	//printf("TINY");
//	globale++;
	t_list		*lst;
	int			i;
	void		*str;

	i = 25;
	lst = ft_lstiter(zone.tiny, one_place_atleasttiny);
	if (lst == NULL)
	{
		globale++;
		str = another_tiny(size);
		
		return(str);
	}
	while(i < 145)
	{
		if(lst->content[i] == FALSE)
		{
			lst->content[i] = TRUE;
//			//printf("malboro, %d, %c ___%p", i, lst->content[i], lst);
//			//printf("malboro, %d, %c ___%p", i, zone.tiny->content[i], zone.tiny);
			return(lst->content + (192 + (64 * (i - 25))));
		}
		i++;
	}
	return(lst->content);
}


void		*first_tiny(size_t size)
{
//	//printf("firsttiny");
	void	*str;
	int		f;

	str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if(str == MAP_FAILED)
	{
		//printf("error MAP_FAILED");
		return(NULL);
	}
	else
	{
		zone.tiny = ft_lstnew(str, PSIZE * 2);
		f = set_tinyheader(zone.tiny);
		return(str + 192);
	}
}

