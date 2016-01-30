/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:07:32 by pboutin           #+#    #+#             */
/*   Updated: 2015/11/30 16:31:41 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		a;

	res = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	a = i;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] >= '0'
			&& str[i + 1] <= '9')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[a] == '-' && str[a + 1] >= '0' && str[a + 1] <= '9')
		return (-res);
	return (res);
}
