/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:47:40 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 11:35:42 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;
	char	*s1;

	i = 0;
	d = (char)c;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == d)
			return (s1 + i);
		i++;
	}
	if (d == '\0')
		return (s1 + i);
	return (0);
}