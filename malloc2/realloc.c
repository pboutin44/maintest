/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:55:06 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/15 00:16:35 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <string.h>

char	identify_letter(void *ptr)
{
	t_list	*tmp;

	tmp = find_browsesmall(ptr);
	if(tmp)
		return('s');
	tmp = find_browsetiny(ptr);
	if(tmp)
		return('t');
	tmp = find_browselarge(ptr);
	if(tmp)
		return('l');
	return('k');
}


void	*ft_realloc(void *ptr, size_t size)
{
	char letter;
	char	*addr;
	char	*ptr1;
	int		i;

	i = 0;
	letter = identify_letter(ptr);
	if(letter == 't' && size < 64)
	{
		return(ptr);
	}
	else if(letter == 's' && size < 1025)
	{
		return(ptr);
	}
	else
	{
		addr = ft_malloc(size);
		ptr1 = (char *)ptr;
		while(ptr1[i] != '\0')
		{
			addr[i] = ptr1[i];
			i++;
		}
		
//		strncpy(ptr, addr, size + 1);
//		printf("addr:::%p  dd%sll", addr, addr);
		ft_free(ptr);
		return((void *)addr);
	}
}
