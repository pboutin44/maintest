/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_norm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 18:10:19 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

char	**points_norm1_norm_norm(char **str2, char **str2bis,
		t_norm1 var, char **str_tmp)
{
	char	*tmp;

	tmp = (char *)malloc(100 * sizeof(char));
	strcpy(tmp, str_tmp[0]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[1]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[2]);
	tmp = strcat(tmp, " ");
	tmp = strcat(tmp, str_tmp[3]);
	strcpy(str2bis[var.l], tmp);
	return (str2bis);
}
