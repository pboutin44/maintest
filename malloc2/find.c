/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:36:06 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/28 20:21:56 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"


t_list      *find_browselarge(void  *ptr)
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
//	printf("COUCOU JE RETOURNE NULL LARGE\n");
	return(NULL);
}

t_list      *find_browsetiny(void   *ptr)
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
	printf("COUCOU JE RETOURNE NULL TINY\n");
	return(NULL);
}

t_list      *find_browsesmall2(t_list   *lst)
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
//	printf("COUCOU JE RETOURNE NULL SMALL2\n");
	return(NULL);
}


t_list      *find_browsesmall(void  *ptr)
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
//	printf("COUCOU JE RETOURNE NULL SMALL\n");
	return(NULL);
}


