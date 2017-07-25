/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_loop_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 15:24:20 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	norm_norm2_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_UP))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds * t->speed +
			t->last1_position + 0.01f;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
		t->last2_position = n->matrix7[14];
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
}

void	norm2_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_LEFT))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed +
			t->last_position - 0.01f;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
		t->last2_position = n->matrix7[14];
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
	norm_norm2_norm_loop(n, t);
}

void	norm_norm3_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_SPACE))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds *
			t->speed + t->last2_position + 0.01f;
		t->last2_position = n->matrix7[14];
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
}

void	norm3_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_DOWN))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds *
			t->speed + t->last1_position - 0.01f;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
		t->last2_position = n->matrix7[14];
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
	norm_norm3_norm_loop(n, t);
}

void	norm_norm4_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_M))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds *
			t->speed + t->last2_position - 0.01f;
		t->last2_position = n->matrix7[14];
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
}
