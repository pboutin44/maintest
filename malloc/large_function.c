/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:46:57 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/15 14:53:01 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"

void	*large_exist(size_t size)
{
    void    *str;
    int     f;
    t_list  *lst;
    t_list  *lst2;
    int     nb;

    nb = size / PSIZE;
    nb = nb + 1;

    str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.large);
        lst = ft_lstnew(str, PSIZE * nb);
        lst2->next = lst;
        return(lst->content);
    }
}

void    *first_large(size_t size)
{
    void    *str;
    int     f;
    int     nb;

    nb = size / PSIZE;
    nb = nb + 1;
    str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        zone.large = ft_lstnew(str, PSIZE * nb);
        f = set_smallheader(zone.small);
        return(str);
    }
}

void	*large_size(size_t	size)
{
	if(zone.large)
        return(large_exist(size));
    else
        return(first_large(size));
}

