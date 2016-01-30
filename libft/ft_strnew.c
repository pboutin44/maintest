/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:03:27 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 19:09:11 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*frch;
	size_t		i;
	size_t		max_size;

	i = 0;
	max_size = (size_t)-1;
	if (size == max_size)
	{
		if ((frch = (char *)malloc(sizeof(char) * (size))) == NULL)
			return (NULL);
	}
	else if ((frch = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (i < size)
	{
		frch[i] = '\0';
		i++;
	}
	frch[i] = '\0';
	return (frch);
}
