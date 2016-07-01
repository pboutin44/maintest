/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:15 by pboutin           #+#    #+#             */
/*   Updated: 2015/11/28 19:37:46 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_size;
	size_t		src_size;
	int			i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size < dst_size)
		return (size + src_size);
	i = 0;
	while (src[i] != '\0' && (dst_size + i + 1) < size)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
