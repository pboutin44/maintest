/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:48:45 by pboutin           #+#    #+#             */
/*   Updated: 2015/11/30 09:35:10 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_size(int number)
{
	int			i;

	i = 0;
	if (number < 0)
		i++;
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;

	i = int_size(n) - 1;
	if ((str = ft_strnew((int_size(n) + 1))) == NULL)
		return (NULL);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}
