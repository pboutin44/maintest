/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:45:57 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 16:36:54 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	size_t			i;
	unsigned char	*d;

	d = b;
	i = 0;
	a = c;
	while (i < len)
	{
		d[i] = a;
		i++;
	}
	return (d);
}
