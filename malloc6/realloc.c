/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:55:06 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/16 23:05:55 by pboutin          ###   ########.fr       */
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


void	*realloc(void *ptr, size_t size)
{
// 	// SEARCH PTR IN ALLOC ZONES => GET PTR ZONE SIZE
// 	// MEMCPY ZONESIZE
// 	// 
// 	void *ptr2 = malloc(size);
// 	if (ptr != NULL)
// 		memcpy(ptr2, ptr, size);
// 	return (ptr2);
// }
	char letter;
	char	*addr;
	char	*ptr1;
	int		i;

	//putchar('A');
	i = 0;
	letter = identify_letter(ptr);
	if(ptr == NULL)
		return(malloc(size));
	if(letter == 't' && size < 64)
	{
		if(find_browsetiny(ptr) != NULL)
		{
			//printf("cacao");
			return(ptr);
		}
		else
			return((void *)0x433333333);
	}
	else if(letter == 's' && size < 1025)
	{
		if(find_browsesmall(ptr) != NULL)
			return(ptr);
		else
			return((void *)0x44444444);
	}
	else
	{
		if(find_browselarge(ptr) != NULL || find_browsetiny(ptr) != NULL || find_browsesmall(ptr) != NULL)
		{
			addr = malloc(size);
			ptr1 = (char *)ptr;
			while(ptr1[i] != '\0')
			{
				addr[i] = ptr1[i];
				i++;
			}
//			strncpy(ptr, addr, size + 1);
//			//printf("addr:::%p  dd%sll", addr, addr);
			free(ptr);
			return((void *)addr);
		}
		else
		{
			return((void *)0x455555555);
		}
	}
}
