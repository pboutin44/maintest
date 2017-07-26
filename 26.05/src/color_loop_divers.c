/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_loop_divers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 14:21:13 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	my_putnbr(int n)
{
	if (n < 0)
	{
		my_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		my_putnbr(n / 10);
		my_putnbr(n % 10);
	}
	else
		my_putchar(n + '0');
}

float	colours_norm(int d, float e)
{
	float	colours;

	if ((d + 1) % 3 == 1)
	{
		colours = e;
	}
	if ((d + 1) % 3 == 2)
	{
		colours = e;
	}
	if ((d + 1) % 3 == 0)
	{
		colours = e;
	}
	return (colours);
}

void	norm_color_table(float *str56, float *colours)
{
	int d;
	int m;
	int a;

	d = 0;
	m = 0;
	a = 0;
	while (str56[d] != 88888888)
	{
		m++;
		if (a > 2)
		{
			a = 0;
		}
		if (a == 0)
			colours[d] = colours_norm(d, 0.1);
		else if (a == 1)
			colours[d] = colours_norm(d, 0.15);
		else if (a == 2)
			colours[d] = colours_norm(d, 0.2);
		if ((d + 1) % 9 == 0)
			a++;
		d++;
	}
}

void	norm_norm_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_RIGHT))
	{
		n->matrix7[12] = t->elapsed_seconds *
			t->speed + t->last_position + 0.01f;
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
}

void	norm_norm_loop(t_norm3 *n, t_norm4 *t)
{
	if (glfwGetKey(n->window, GLFW_KEY_EQUAL))
	{
		n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
		t->last_position = n->matrix7[12];
		n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
		t->last1_position = n->matrix7[13];
		n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
		t->last2_position = n->matrix7[14];
		t->teta = t->teta + 0.01;
		n->matrix8 = matrix_y(t->teta, n->l);
		n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
		glUseProgram(n->shader_programme);
		glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix3);
	}
	norm_norm_norm_loop(n, t);
}
