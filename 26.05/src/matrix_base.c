/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/24 19:13:47 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float	*norm_matrix(float *matrix)
{
	matrix = (float *)malloc(16 * sizeof(float));
	matrix[0] = 0.707;
	matrix[1] = 0.0;
	matrix[2] = -0.707;
	matrix[3] = 0.0;
	matrix[4] = 0.0;
	matrix[5] = 1.0;
	matrix[6] = 0.0;
	matrix[7] = 0.0;
	matrix[8] = 0.707;
	matrix[9] = 0.0;
	matrix[10] = 0.707;
	matrix[11] = 0.0;
	matrix[12] = 0.0;
	matrix[13] = 0.0;
	matrix[14] = -1.414;
	matrix[15] = 1.0;
	return (matrix);
}

float	*norm_matrix6(float *matrix6)
{
	matrix6 = (float *)malloc(16 * sizeof(float));
	matrix6[0] = 0.707;
	matrix6[1] = 0.0;
	matrix6[2] = -0.707;
	matrix6[3] = 0.0;
	matrix6[4] = 0.0;
	matrix6[5] = 1.0;
	matrix6[6] = 0.0;
	matrix6[7] = 0.0;
	matrix6[8] = 0.707;
	matrix6[9] = 0.0;
	matrix6[10] = 0.707;
	matrix6[11] = 0.0;
	matrix6[12] = 0.0;
	matrix6[13] = 0.0;
	matrix6[14] = -1.414;
	matrix6[15] = 1.0;
	return (matrix6);
}

float	*norm_matrix7(float *matrix7)
{
	matrix7 = (float *)malloc(16 * sizeof(float));
	matrix7[0] = 1.0;
	matrix7[1] = 0.0;
	matrix7[2] = 0.0;
	matrix7[3] = 0.0;
	matrix7[4] = 0.0;
	matrix7[5] = 1.0;
	matrix7[6] = 0.0;
	matrix7[7] = 0.0;
	matrix7[8] = 0.0;
	matrix7[9] = 0.0;
	matrix7[10] = 1.0;
	matrix7[11] = 0.0;
	matrix7[12] = 0.0;
	matrix7[13] = 0.0;
	matrix7[14] = 0.0;
	matrix7[15] = 1.0;
	return (matrix7);
}

float	*norm_matrix1(float *matrix1)
{
	matrix1 = (float *)malloc(16 * sizeof(float));
	matrix1[0] = 1.0;
	matrix1[1] = 0.0;
	matrix1[2] = 0.0;
	matrix1[3] = 0.0;
	matrix1[4] = 0.0;
	matrix1[5] = 1.0;
	matrix1[6] = 0.0;
	matrix1[7] = 0.0;
	matrix1[8] = 0.0;
	matrix1[9] = 0.0;
	matrix1[10] = 1.0;
	matrix1[11] = 0.0;
	matrix1[12] = 0.0;
	matrix1[13] = 0.0;
	matrix1[14] = 0.0;
	matrix1[15] = 1.0;
	return (matrix1);
}

float	*norm_matrix2(float *matrix2)
{
	matrix2 = (float *)malloc(16 * sizeof(float));
	matrix2[0] = 1.0;
	matrix2[1] = 0.0;
	matrix2[2] = 0.0;
	matrix2[3] = 0.0;
	matrix2[4] = 0.0;
	matrix2[5] = 1.0;
	matrix2[6] = 0.0;
	matrix2[7] = 0.0;
	matrix2[8] = 0.0;
	matrix2[9] = 0.0;
	matrix2[10] = 1.0;
	matrix2[11] = 0.0;
	matrix2[12] = -0.5;
	matrix2[13] = 0.0;
	matrix2[14] = 0.0;
	matrix2[15] = 1.0;
	return (matrix2);
}
