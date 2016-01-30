/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:15:22 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/03 10:05:06 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_number(char const *s, char c)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		result++;
		if (s[i - 1] == c)
			result -= 1;
	}
	return (result);
}

static int		words_size(char const *s, char c, int i)
{
	int		res;

	res = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

static char		**new_tab(char const *s, char c, int result)
{
	char		**str;
	int			i;
	int			j;
	int			word_size;

	i = 0;
	j = 0;
	if (!(str = (char**)malloc(sizeof(char*) * result + 1)))
		return (NULL);
	while (i < result)
	{
		word_size = 0;
		while (s[j] == c && s[j] != '\0')
			j++;
		word_size = words_size(s, c, j);
		while (s[j] != c && s[j] != '\0')
			j++;
		str[i] = (char*)malloc(sizeof(char) * (word_size + 1));
		if (!str[i])
			return (NULL);
		i++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			j;
	int			k[2];

	k[0] = 0;
	k[1] = 0;
	if (!s)
		return (NULL);
	if (!(str = new_tab(s, c, words_number(s, c))))
		return (NULL);
	while (k[0] < words_number(s, c))
	{
		j = 0;
		while (s[k[1]] == c && s[k[1]] != '\0')
			k[1]++;
		while (s[k[1]] != c && s[k[1]] != '\0')
		{
			str[k[0]][j] = s[k[1]];
			j++;
			k[1]++;
		}
		str[k[0]++][j] = '\0';
	}
	str[k[0]] = NULL;
	return (str);
}
