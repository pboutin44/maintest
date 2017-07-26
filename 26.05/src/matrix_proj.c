/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_proj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 16:32:12 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_norm5	norm_proj_norm(void)
{
	t_norm5	p;

	p.near = 0.1f;
	p.far = 100.0f;
	p.fov = 67.0f * ONE_DEG_IN_RAD;
	p.aspect = (float)WIDTH / (float)HEIGHT;
	p.range = tan(p.fov * 0.5f) * p.near;
	p.sx = (2.0f * p.near) / (p.range * p.aspect + p.range * p.aspect);
	p.sy = p.near / p.range;
	p.sz = -(p.far + p.near) / (p.far - p.near);
	p.pz = -(2.0f * p.far * p.near) / (p.far - p.near);
	return (p);
}

float	*proj_norm(void)
{
	t_norm5	p;

	p = norm_proj_norm();
	p.proj_mat = (float *)malloc(sizeof(float) * 16);
	p.proj_mat[0] = p.sx;
	p.proj_mat[1] = 0.0f;
	p.proj_mat[2] = 0.0f;
	p.proj_mat[3] = 0.0f;
	p.proj_mat[4] = 0.0f;
	p.proj_mat[5] = p.sy;
	p.proj_mat[6] = 0.0f;
	p.proj_mat[7] = 0.0f;
	p.proj_mat[8] = 0.0f;
	p.proj_mat[9] = 0.0f;
	p.proj_mat[10] = p.sz;
	p.proj_mat[11] = -1.0f;
	p.proj_mat[12] = 0.0f;
	p.proj_mat[13] = 0.0f;
	p.proj_mat[14] = p.pz;
	p.proj_mat[15] = 0.0f;
	return (p.proj_mat);
}

float	*view_norm(void)
{
	float	*view_mat;

	view_mat = (float *)malloc(sizeof(float) * 16);
	view_mat[0] = 1.0f;
	view_mat[1] = 0.0f;
	view_mat[2] = 0.0f;
	view_mat[3] = 0.0f;
	view_mat[4] = 0.0f;
	view_mat[5] = 1.0f;
	view_mat[6] = 0.0f;
	view_mat[7] = 0.0f;
	view_mat[8] = 0.0f;
	view_mat[9] = 0.0f;
	view_mat[10] = 1.0f;
	view_mat[11] = 0.0f;
	view_mat[12] = 0.0f;
	view_mat[13] = 0.0f;
	view_mat[14] = -2.0f;
	view_mat[15] = 1.0f;
	return (view_mat);
}
