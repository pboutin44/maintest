/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:34:09 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 11:32:34 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst1;
	const unsigned char	*src1;
	unsigned char		a;

	dst1 = dst;
	src1 = src;
	i = 0;
	a = c;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == a)
			return (dst1 + (i + 1));
		i++;
	}
	return (NULL);
}
