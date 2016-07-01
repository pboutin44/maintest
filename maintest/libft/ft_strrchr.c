/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:55:41 by pboutin           #+#    #+#             */
/*   Updated: 2015/11/28 20:03:07 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;
	char	*v;

	v = (char *)s;
	i = 0;
	d = (char)c;
	while (v[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (v[i] == d)
			return (v + i);
		i--;
	}
	return (NULL);
}
