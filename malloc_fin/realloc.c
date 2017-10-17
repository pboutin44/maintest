/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:55:06 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 21:40:17 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <string.h>

char		identify_letter(void *ptr)
{
	t_list	*tmp;

	tmp = find_browsesmall(ptr);
	if (tmp)
		return ('s');
	tmp = find_browsetiny(ptr);
	if (tmp)
		return ('t');
	tmp = find_browselarge(ptr);
	if (tmp)
		return ('l');
	return ('k');
}

void		*realloc_norm(t_norm_reall *norm)
{
	if (find_browselarge(norm->ptr) != NULL ||
			find_browsetiny(norm->ptr) != NULL ||
			find_browsesmall(norm->ptr) != NULL)
	{
		norm->addr = malloc(norm->size);
		norm->ptr1 = (char *)norm->ptr;
		while (norm->ptr1[norm->i] != '\0')
		{
			norm->addr[norm->i] = norm->ptr1[norm->i];
			norm->i++;
		}
		free(norm->ptr);
		return ((void *)norm->addr);
	}
	else
		return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	char			letter;
	t_norm_reall	*norm;

	norm->ptr = ptr;
	norm->size = size;
	norm->i = 0;
	letter = identify_letter(norm->ptr);
	if (norm->ptr == NULL)
		return (malloc(norm->size));
	if (letter == 't' && norm->size < 64)
	{
		if (find_browsetiny(norm->ptr) != NULL)
			return (norm->ptr);
		else
			return (NULL);
	}
	else if (letter == 's' && norm->size < 1025)
	{
		if (find_browsesmall(norm->ptr) != NULL)
			return (norm->ptr);
		else
			return (NULL);
	}
	else
		return (realloc_norm(norm));
}
