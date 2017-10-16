/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test666.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:50:46 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/16 14:28:27 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "malloc.h"
#define M (1024 * 1024)

void print(char *s)
{
	write(1,s,strlen(s));
}

int		main()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)ft_malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)ft_realloc(addr1, 128 * M);
	addr3[127*M] = 42;
//	print("okokok\n");
	print(addr3);
//	//printf("addr3::::%p", addr3);
//	print("okokok");
	return(0);
}
/*
int		main()
{
	char *addr1;
	char *addr2;
	char *addr3;

	addr1 = (char*)ft_malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char *)ft_malloc(16 * M);
	addr3 = (char*)ft_realloc(addr1, 128 * M);
	addr3[127*M] = 42;
//	print("okokok\n");
	print(addr3);
//	//printf("addr3::::%p", addr3);
//	print("okokok");
	return(0);
}
*/
/*int		main()
{
	char	*addr;

	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void*)addr + 5);
	if (ft_realloc((void*)addr + 5, 10)==NULL)
		print("Bonjours\n");
	else
		print("Aurevoir\n");

}*/

/*int	main()
{
	ft_malloc(1024);
	ft_malloc(1024 * 32);
	ft_malloc(1024 * 1024);
	ft_malloc(1024 * 1024 * 16);
	ft_malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return(0);

}*/
