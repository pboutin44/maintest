/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/26 18:24:06 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

char	**points_norm1_norm_norm1(char **str2, char **str2bis,
t_norm1 var, char **str_tmp)
{
	char	*tmp;

	tmp = (char *)malloc(100 * sizeof(char));
	strcpy(tmp, str_tmp[0]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[1]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[3]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[4]);
	strcpy(str2bis[var.l], tmp);
	return (str2bis);
}

char	**points_norm1_norm(char **str2, char **str2bis,
char **str_tmp, t_norm1 var)
{
	while (strcmp(str2[var.j], "off") != 0)
	{
		var.i = 0;
		var.k = 0;
		while (str2[var.j][var.i] != '\0')
		{
			if (str2[var.j][var.i] == ' ')
				var.k++;
			var.i++;
		}
		if (var.k == 3)
			str2bis[var.l] = str2[var.j];
		else
		{
			str_tmp = ft_strsplit(str2[var.j], ' ');
			str2bis = points_norm1_norm_norm(str2, str2bis, var, str_tmp);
			var.l++;
			str2bis = points_norm1_norm_norm1(str2, str2bis, var, str_tmp);
		}
		var.j++;
		var.l++;
	}
	str2bis[var.l] = "off";
	return (str2bis);
}

char	**points_norm1(char **str_tmp, char **str2)
{
	char	**str2bis;
	char	*tmp;
	t_norm1	var;

	var.j = 0;
	var.i = 0;
	var.k = 0;
	var.l = 0;
	str2bis = (char **)malloc(10000 * sizeof(char *));
	while (var.j < 10000)
	{
		str2bis[var.j] = (char *)malloc(600 * sizeof(char));
		var.j++;
	}
	var.j = 0;
//	puts("tidou");
	str2bis = points_norm1_norm(str2, str2bis, str_tmp, var);
	return (str2bis);
}

int		points_norm_norm(float *str3, char **str_tmp, int v)
{
	int		y;

	y = 1;
	while (y < 4)
	{
		str3[v] = atof(str_tmp[y]);
		v++;
		y++;
	}
	return (v);
}

float	*points_norm(char **str2bis, char **str_tmp2,
		char **str_tmp, char **str1)
{
	float	*str3;
	int		i;
	int		v;
	char	*tmp;

	str3 = (float *)malloc(6000 * sizeof(float));
	v = 0;
	i = 0;
	while (strcmp(str2bis[i], "off") != 0)
	{
		tmp = (char *)malloc(100 * sizeof(char));
		str_tmp2 = ft_strsplit(str2bis[i], ' ');
		str_tmp = ft_strsplit(str1[atoi(str_tmp2[1]) - 1], ' ');
		v = points_norm_norm(str3, str_tmp, v);
		free(str_tmp);
		str_tmp = ft_strsplit(str1[atoi(str_tmp2[2]) - 1], ' ');
		v = points_norm_norm(str3, str_tmp, v);
		free(str_tmp);
		str_tmp = ft_strsplit(str1[atoi(str_tmp2[3]) - 1], ' ');
		v = points_norm_norm(str3, str_tmp, v);
		i++;
	}
	str3[v] = 88888888;
	return (str3);
}
