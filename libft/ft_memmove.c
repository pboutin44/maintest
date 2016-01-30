/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:45 by pboutin           #+#    #+#             */
/*   Updated: 2015/11/30 16:39:10 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;
	char	*temp;

	temp = (char *)malloc(len * sizeof(char));
	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (i < len)
	{
		temp[i] = src1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst1[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst1);
}
