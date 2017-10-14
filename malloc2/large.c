/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:32:31 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/14 22:30:07 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "malloc.h"

void		*already_large(size_t	size)
{
	void	*str;
	int		f;
	t_list	*lst;
	t_list	*lst2;
	int		nb;

//	printf("NOTfirst_large");
	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return (NULL);
	}
	else
	{
		lst2 = browse_lst(zone.large);
		lst = ft_lstnew(str, PSIZE * nb);
		lst2->next = lst;
		return (lst->content + 25);
	}
}

void		*first_large(size_t	size)
{
	void	*str;
	int		f;
	int		nb;

	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//	printf("first_large  %p***%d", str, PSIZE * nb);
	if (str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return (NULL);
	}
	else
	{
		zone.large = ft_lstnew(str, PSIZE * nb);
		return (str + 25);
	}
}

