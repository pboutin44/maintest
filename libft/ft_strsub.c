/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:40:46 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 14:27:54 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char					*dst;
	unsigned int			i;
	size_t					j;

	j = 0;
	i = 0;
	if (s)
	{
		dst = (char *)malloc((len + 1) * (sizeof(char)));
		if (dst != NULL)
		{
			while (i < start)
				i++;
			while (j < len)
			{
				dst[j] = s[i + j];
				j++;
			}
			dst[j] = '\0';
		}
		return (dst);
	}
	return (NULL);
}
