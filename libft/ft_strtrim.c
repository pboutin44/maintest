/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:26:07 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/03 09:57:06 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!ft_strcmp(s, ""))
		return (str = ft_strdup(""));
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
