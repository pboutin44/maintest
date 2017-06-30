/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 17:55:39 by pboutin           #+#    #+#             */
/*   Updated: 2017/06/27 20:11:37 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

float	*matrix_y(float teta, float x)
{
	float *final_matrix;

	final_matrix = (float *)malloc(16 * sizeof(float));
	final_matrix[0] = cos(teta);
	final_matrix[1] = 0;
	final_matrix[2] = -sin(teta);
	final_matrix[3] = 0;
	final_matrix[4] = 0;
	final_matrix[5] = 1;
	final_matrix[6] = 0;
	final_matrix[7] = 0;
	final_matrix[8] = sin(teta);
	final_matrix[9] = 0;
	final_matrix[10] = cos(teta);
	final_matrix[11] = 0;
	final_matrix[12] = -x * sin(teta);
	final_matrix[13] = 0;
	final_matrix[14] = -x * cos(teta);
	final_matrix[15] = 1;
	return (final_matrix);
}

void	norm_prod_mat4(float *mat, float mat1[], float mat2[])
{
	mat[8] = mat2[8] * mat1[0] + mat2[9] * mat1[4] +
		mat2[10] * mat1[8] + mat2[11] * mat1[12];
	mat[9] = mat2[8] * mat1[1] + mat2[9] * mat1[5] +
		mat2[10] * mat1[9] + mat2[11] * mat1[13];
	mat[10] = mat2[8] * mat1[2] + mat2[9] * mat1[6] +
		mat2[10] * mat1[10] + mat2[11] * mat1[14];
	mat[11] = mat2[8] * mat1[3] + mat2[9] * mat1[7] +
		mat2[10] * mat1[11] + mat2[11] * mat1[15];
	mat[12] = mat2[12] * mat1[0] + mat2[13] * mat1[4] +
		mat2[14] * mat1[8] + mat2[15] * mat1[12];
	mat[13] = mat2[12] * mat1[1] + mat2[13] * mat1[5] +
		mat2[14] * mat1[9] + mat2[15] * mat1[13];
	mat[14] = mat2[12] * mat1[2] + mat2[13] * mat1[6] +
		mat2[14] * mat1[10] + mat2[15] * mat1[14];
	mat[15] = mat2[12] * mat1[3] + mat2[13] * mat1[7] +
		mat2[14] * mat1[11] + mat2[15] * mat1[15];
}

float	*produit_matricielle4(float mat1[], float mat2[], float teta)
{
	float	*final_matrix;

	final_matrix = (float *)malloc(16 * sizeof(float));
	final_matrix[0] = mat2[0] * mat1[0] + mat2[1] * mat1[4] +
		mat2[2] * mat1[8] + mat2[3] * mat1[12];
	final_matrix[1] = mat2[0] * mat1[1] + mat2[1] * mat1[5] +
		mat2[2] * mat1[9] + mat2[3] * mat1[13];
	final_matrix[2] = mat2[0] * mat1[2] + mat2[1] * mat1[6] +
		mat2[2] * mat1[10] + mat2[3] * mat1[14];
	final_matrix[3] = mat2[0] * mat1[3] + mat2[1] * mat1[7] +
		mat2[2] * mat1[11] + mat2[3] * mat1[15];
	final_matrix[4] = mat2[4] * mat1[0] + mat2[5] * mat1[4] +
		mat2[6] * mat1[8] + mat2[7] * mat1[12];
	final_matrix[5] = mat2[4] * mat1[1] + mat2[5] * mat1[5] +
		mat2[6] * mat1[9] + mat2[7] * mat1[13];
	final_matrix[6] = mat2[4] * mat1[2] + mat2[5] * mat1[6] +
		mat2[6] * mat1[10] + mat2[7] * mat1[14];
	final_matrix[7] = mat2[4] * mat1[3] + mat2[5] * mat1[7] +
		mat2[6] * mat1[11] + mat2[7] * mat1[15];
	norm_prod_mat4(final_matrix, mat1, mat2);
	return (final_matrix);
}

float	*rotation_y(float mat1[], float mat2[], float teta)
{
	float *final_matrix;

	final_matrix = (float *)malloc(16 * sizeof(float));
	final_matrix[0] = cos(teta) * mat1[0] - sin(teta) * mat1[8];
	final_matrix[1] = cos(teta) * mat1[1] - sin(teta) * mat1[9];
	final_matrix[2] = cos(teta) * mat1[2] - sin(teta) * mat1[10];
	final_matrix[3] = cos(teta) * mat1[3] - sin(teta) * mat1[11];
	final_matrix[4] = mat1[4];
	final_matrix[5] = mat1[5];
	final_matrix[6] = mat1[6];
	final_matrix[7] = mat1[7];
	final_matrix[8] = sin(teta) * mat1[0] + cos(teta) * mat1[8];
	final_matrix[9] = sin(teta) * mat1[1] + cos(teta) * mat1[9];
	final_matrix[10] = sin(teta) * mat1[2] + cos(teta) * mat1[10];
	final_matrix[11] = sin(teta) * mat1[3] + cos(teta) * mat1[11];
	final_matrix[12] = -2 * cos(teta) * mat1[8] + 1 * mat1[12];
	final_matrix[13] = -2 * cos(teta) * mat1[9] + 1 * mat1[13];
	final_matrix[14] = -2 * cos(teta) * mat1[10] + 1 * mat1[14];
	final_matrix[15] = -2 * cos(teta) * mat1[11] + 1 * mat1[15];
	return (final_matrix);
}
