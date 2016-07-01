/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:32:03 by pboutin           #+#    #+#             */
/*   Updated: 2016/01/07 11:50:24 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stat		flag(t_stat stat)
{
	if (stat.flag == 1)
	{
		stat.line1 = "";
		stat.stock = "";
		stat.flag = 0;
		stat.i = 3;
	}
	if (stat.i != 3)
		stat.flag = 1;
	return (stat);
}

static t_stat		stock1(t_stat stat, char a, char **line)
{
	int				y[2];

	y[0] = 0;
	y[1] = 0;
	while (stat.stock[y[0]] != a)
		y[0]++;
	y[0]++;
	stat.line1 = ft_strnew(y[0]);
	while (stat.stock[y[1]] != a)
	{
		stat.line1[y[1]] = stat.stock[y[1]];
		y[1]++;
	}
	stat.line1[y[1]] = '\0';
	if (!(ft_strchr(stat.stock, '\n')) && stat.stock[0] != '\0')
		stat = flag(stat);
	(*line) = stat.line1;
	(ft_strchr(stat.stock, '\n') && !stat.stock) ? free(stat.stock) : "";
	if ((ft_strchr(stat.stock, '\n')))
		stat.stock = ft_strchr(stat.stock, '\n') + 1;
	return (stat);
}

static t_stat		error_fd(t_stat stat, int fd)
{
	if (stat.stock && stat.fdbis != fd && stat.fdbis)
	{
		stat.stock = "";
		stat.flag = 0;
	}
	stat.fdbis = fd;
	return (stat);
}

int					get_next_line(int const fd, char **line)
{
	static t_stat	stat = {"", 0, {0}, 0, 0, "", 0};

	stat = error_fd(stat, fd);
	while ((stat.ret = read(fd, stat.buf, BUFF_SIZE)) != 0 && stat.ret != -1)
	{
		stat.buf[stat.ret] = '\0';
		stat.stock = ft_strjoin(stat.stock, stat.buf);
		if (stat.stock && ft_strchr(stat.stock, '\n'))
		{
			stat = stock1(stat, '\n', line);
			return (1);
		}
	}
	if (ft_strchr(stat.stock, '\n'))
	{
		stat = stock1(stat, '\n', line);
		return (1);
	}
	if (stat.ret == -1)
		return (-1);
	if (!(ft_strchr(stat.stock, '\n')))
		stat = stock1(stat, '\0', line);
	return (stat.flag);
}
