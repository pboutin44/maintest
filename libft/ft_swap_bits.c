/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:24:28 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/01 21:28:56 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_swap_octets(unsigned char octet, char *bytes)
{
	unsigned char	res;
	int				i;
	int				div;

	div = 128;
	i = 4;
	res = 0;
	while (i < 8)
	{
		if (bytes[i] == 1)
			res += div;
		div /= 2;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (bytes[i] == 1)
			res += div;
		div /= 2;
		i++;
	}
	octet = res;
	return (octet);
}

unsigned char	swap_bits(unsigned char octet)
{
	char			bytes[8];
	int				index;
	unsigned char	octet_copy;
	int				div;

	index = 0;
	div = 128;
	octet_copy = octet;
	while (index < 8)
	{
		bytes[index] = 0;
		index++;
	}
	index = 0;
	while (octet_copy > 0)
	{
		if (div <= octet_copy)
		{
			bytes[index] = 1;
			octet_copy -= div;
		}
		div /= 2;
		index++;
	}
	return (ft_swap_octets(octet, bytes));
}
