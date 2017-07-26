/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 18:15:19 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float	*point(char *objet)
{
	t_norm2 var;

	var.fd = open(objet, O_RDONLY);
	var.str1 = points_norm3(var.fd);
	var.str2 = points_norm2(var.fd);
	var.str2bis = points_norm1(var.str_tmp, var.str2);
	free(var.str_tmp);
	return (points_norm(var.str2bis, var.str_tmp2, var.str_tmp, var.str1));
}

void	init_points_norm3(t_norm8 *t)
{
	t->flag = 0;
	t->str1 = (char **)malloc(5000 * sizeof(char *));
	t->i = 0;
	while (t->i < 5000)
	{
		t->str1[t->i] = (char *)malloc(600 * sizeof(char));
		t->i++;
	}
	t->i = 0;
}

char	**points_norm3(int fd)
{
	t_norm8		t;

	init_points_norm3(&t);
	while (t.flag != 1)
	{
		t.str = get_next_line(fd);
		if (t.str[0] == 's')
		{
			strcpy(t.str1[t.i], "off");
			t.flag = 1;
			t.i++;
		}
		else
		{
			if (t.str[0] == 'v')
			{
				t.str1[t.i] = t.str;
				t.i++;
			}
		}
	}
	return (t.str1);
}

char	**points_norm2_norm(int fd, char **str2, int flag)
{
	char	*str;
	int		i;

	flag = 0;
	i = 0;
	while (flag != 1)
	{
		str = get_next_line(fd);
		if (!str || str[0] != 'f')
		{
			str2[i] = "off";
			flag = 1;
			i++;
		}
		else
		{
			if (str[0] == 'f')
			{
				str2[i] = str;
				i++;
			}
		}
	}
	return (str2);
}

char	**points_norm2(int fd)
{
	int		i;
	int		flag;
	char	**str2;

	str2 = (char **)malloc(10000 * sizeof(char *));
	i = 0;
	while (i < 10000)
	{
		str2[i] = (char *)malloc(600 * sizeof(char));
		i++;
	}
	return (points_norm2_norm(fd, str2, flag));
}
