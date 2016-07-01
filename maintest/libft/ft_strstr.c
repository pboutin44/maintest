/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:56:16 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 19:01:11 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	while (s2[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[j + i] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
