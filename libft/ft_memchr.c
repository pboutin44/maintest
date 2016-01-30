/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:48:47 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 14:51:26 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	b;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (b == s1[i])
			return (s1 + i);
		i++;
	}
	return (NULL);
}
