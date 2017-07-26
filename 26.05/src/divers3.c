/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 18:26:16 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

char	*get_next_line(const int fd)
{
	static char	buff[MEM_SIZE];
	static int	nbinbuff = 0;
	static int	start;
	int			treat;
	char		*line;

	line = 0;
	treat = 0;
	while (1 == 1)
	{
		if (nbinbuff <= start)
		{
			start = 0;
			if (!(nbinbuff = read(fd, buff, MEM_SIZE)))
				return (line);
			if (nbinbuff == -1)
				return (NULL);
			treat = 0;
		}
		if (buff[start + treat] == '\n')
			return (line = add_to_line(line, treat, buff, &start));
		if (start + treat == nbinbuff - 1)
			line = add_to_line(line, treat + 1, buff, &start);
		treat = treat + 1;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			ft_putchar(n + 48);
		}
	}
}

char	*ft_strcat(char *s1, const char *s2)
{
	char	*cur1;
	char	*cur2;

	cur1 = s1;
	cur2 = (char *)s2;
	while (*cur1 != '\0')
	{
		cur1++;
	}
	while (*cur2 != '\0')
	{
		*cur1 = *cur2;
		cur1++;
		cur2++;
	}
	*cur1 = '\0';
	return (s1);
}
