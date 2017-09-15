/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:32:13 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/15 14:41:31 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int     set_smallheader(t_list  *lst)
{
	int     i;

	i = 1;
	lst->content[0] = TRUE;
	while(i < 100)
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

    str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.tiny);
        lst = ft_lstnew(str, PSIZE * 101);
        f = set_smallheader(lst);
        lst2->next = lst;
        return(lst->content + 4095);
    }
}


 void    *first_small(size_t size)
{
    void    *str;
    int     f;

    str = mmap(0, PSIZE * 101, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        zone.small = ft_lstnew(str, PSIZE * 101);
        f = set_smallheader(zone.small);
        return(str + 4095);
    }
}


void    *small_exist(size_t size)
{
    t_list      *lst;
    int         i;
    void        *str;

    i = 0;
    lst = ft_lstiter(zone.small, one_place_atleastsmall);
    if(lst == NULL)
    {
        str = another_tiny(size);

    }
    while(i < 126)
    {
        if(lst->content[i] == FALSE)
        {
            printf("&&&&%d&&&&", i);
            zone.tiny->content[i] = TRUE;
            return(lst->content + (127 + (64 * i)));
        }
        i++;
    }

    return(lst->content);
}


void    *size_small(size_t size)
{
    if(zone.small)
        return(small_exist(size));
    else
        return(first_small(size));
}
