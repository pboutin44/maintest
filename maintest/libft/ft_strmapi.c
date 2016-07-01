/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:13:42 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 19:16:58 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	if (s && f)
	{
		dst = ft_strnew(ft_strlen(s));
		if (dst != NULL)
		{
			while (s[i] != '\0')
			{
				dst[i] = f(i, s[i]);
				i++;
			}
			dst[i] = '\0';
			return (dst);
		}
		return (NULL);
	}
	return (NULL);
}
