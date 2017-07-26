/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 18:21:20 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

char		**new_tab(char const *s, char c, int result)
{
	char	**str;
	int		i;
	int		j;
	int		word_size;

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

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;
	int		k[2];

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

int			my_put_nbr(int n)
{
	if (n < 0)
	{
		my_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		my_put_nbr(n / 10);
		my_putchar(n % 10 + '0');
	}
	if (n < 10)
	{
		my_putchar(n % 10 + '0');
	}
	return (n);
}

char		*my_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n < i)
		dest[i] = '\0';
	return (dest);
}

char		*add_to_line(char *line, int treat, char *buff, int *start)
{
	char	*newlen;
	int		oldlen;

	if (line != 0)
		oldlen = my_strlen(line);
	else
		oldlen = 0;
	newlen = malloc((oldlen + treat + 1) * sizeof(*newlen));
	if (line != 0)
		my_strncpy(newlen, line, oldlen);
	else
		my_strncpy(newlen, "", oldlen);
	newlen[oldlen + treat] = 0;
	my_strncpy(newlen + oldlen, buff + *start, treat);
	if (line)
		free(line);
	*start = *start + (treat + 1);
	return (newlen);
}
