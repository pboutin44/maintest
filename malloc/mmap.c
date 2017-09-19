/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:56:44 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/19 18:02:42 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int argc, char **argv)
{
	fflush(stdout);
	char	*tiny;
	int		i;
	int		nb;
	char	c;
	char	*str;
	int		nbr;

	char	*test;
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	void	*test6;

	if(zone.tiny)
		putchar('<');
	else
		putchar('>');
	test = ft_malloc(10);
	test1 = ft_malloc(10);
	test2 = ft_malloc(10);
	test3 = ft_malloc(4000);
	test4 = ft_malloc(5000);
	test5 = ft_malloc(6000);
	test6 = ft_malloc(3000);
	printf("**y*%c****%p***%c**%p", test[0], test, test1[0], test1);
	printf("\n**y*%c****%p**", test5[0], test5);
	putchar('\n');
	ft_free(test5);
	ft_free(test2);
	ft_free(test1);
	ft_free(test);
	ft_free(test3);

	
	return(0);
}


int		one_place_atleast(t_list	*elem)
{
	int		i;

	i = 0;
	while(i < 126)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

int		one_place_atleastsmall(t_list	*elem)
{
	int		i;

	i = 0;
	while(i < 100)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

void	*ft_malloc(size_t size)
{
	if(size <= 0)
		return(NULL);
	if(size < 64)
	{
		return(size_tiny(size));
	}
	else if(size < 4096)
	{
		return(size_small(size));
	}
	else
	{
		return(large_size(size));
//		return(0);
	}
}

t_list		*find_browselarge(void	*ptr)
{

   t_list  *tmp;

	tmp = zone.large;
	while(tmp)
	{
		if(tmp->content == ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}

t_list		*find_browsetiny(void	*ptr)
{

   t_list  *tmp;

	tmp = zone.tiny;
	while(tmp)
	{
		if(tmp->content <= (char *)ptr && tmp->content + 2 * PSIZE >= (char *)ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}

t_list		*find_browsesmall2(t_list	*lst)
{
   t_list  *tmp;

	tmp = zone.small;
	while(tmp)
	{
		if(tmp->next == lst)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}

t_list		*find_browsesmall(void	*ptr)
{
   t_list  *tmp;

	tmp = zone.small;
	while(tmp)
	{
		if(tmp->content <= (char *)ptr && tmp->content + 101 * PSIZE >= (char *)ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}
