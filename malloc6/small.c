/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:16:27 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/16 13:39:21 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"



int     one_place_atleastsmall(t_list   *elem)
{
	int		i;

	i = 25;
	while(i < 129)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}


int     set_smallheader(t_list  *lst)
{
	int     i;

	i = 26;
	lst->content[25] = TRUE;
	while(i < 129)
	{
		lst->content[i] = FALSE;
		i++;
	}
	return(1);
}

void    *another_small(size_t size)
{
    void    *str;
    int     f;
    t_list  *lst;
    t_list  *lst2;

    str = mmap(0, PSIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        //printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.small);
        lst = ft_lstnew(str, PSIZE * 26);
        f = set_smallheader(lst);
        lst2->next = lst;
        return(lst->content + 1023);
    }
}


void		*already_small(size_t size)
{
	t_list		*lst;
	int			i;
	void		*str;

	i = 25;
	lst = ft_lstiter(zone.small, one_place_atleastsmall);
	if (lst == NULL)
	{
		//printf("SMALL***");
		globale++;
		str = another_small(size);
		
		return(str);
	}
	while(i < 129)
	{
		if(lst->content[i] == FALSE)
		{
		//	//printf("malboro, %d, %c", i, lst->content[i]);
		//	globale++;
			lst->content[i] = TRUE;

		//	//printf("\nalloc, %d, %p", i, lst->content + (1023 + (1024 *(i - 25))));
			return(lst->content + (1023 + (1024 * (i - 25))));
		}
		i++;
	}
	return(lst->content);
}

void		*first_small(size_t size)
{
			globale++;
//	//printf("firstsmall");
	void	*str;
	int		f;

	str = mmap(0, PSIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if(str == MAP_FAILED)
	{
		//printf("error MAP_FAILED");
		return(NULL);
	}
	else
	{
		zone.small = ft_lstnew(str, PSIZE * 26);
		f = set_smallheader(zone.small);
		return(str + 1023);
	}
}
