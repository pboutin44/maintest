/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_loop_2_invers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/26 18:52:35 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	norm4_norm_loop(t_norm3 *n, t_norm4 *t)
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
	norm_norm4_norm_loop(n, t);
}

void	norm5_norm_loop(t_norm3 *n)
{
	if (glfwGetKey(n->window, GLFW_KEY_N))
	{
		n->textura = 1;
		n->uniformid = glGetUniformLocation(n->shader_programme, "textura");
		glUseProgram(n->shader_programme);
		glUniform1f(n->uniformid, n->textura);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(n->shader_programme);
	glBindVertexArray(n->vao);
	glDrawArrays(GL_TRIANGLES, 0, 3 * n->nb_tr);
	glfwPollEvents();
	glfwSwapBuffers(n->window);
}

void	norm_loop(int textura, t_norm3 *n)
{
	t_norm4 t;

	t.teta = 0;
	t.speed = 1.0f;
	t.last_position = 0.0f;
	t.last1_position = 0.0f;
	t.last2_position = 0.0f;
	while (!glfwWindowShouldClose(n->window))
	{
		t.previous_seconds = glfwGetTime();
		t.current_seconds = glfwGetTime();
		t.elapsed_seconds = t.current_seconds - t.previous_seconds;
		t.elapsed1_seconds = t.current_seconds - t.previous_seconds;
		t.elapsed2_seconds = t.current_seconds - t.previous_seconds;
		t.elapsed3_seconds = t.current_seconds - t.previous_seconds;
		t.previous_seconds = t.current_seconds;
		if (fabs(t.last_position) > 1.0f)
			t.speed = -t.speed;
		norm_norm_loop(n, &t);
		norm2_norm_loop(n, &t);
		norm3_norm_loop(n, &t);
		norm4_norm_loop(n, &t);
		norm5_norm_loop(n);
	}
}

void	norm_norm_invers(t_norm6 *t, t_norm7 *u, char **argv)
{
	t->width_in_bytes = 128 * 4;
	u->top = NULL;
	u->bottom = NULL;
	u->temp = 0;
	t->half_height = 64;
	t->x = 128;
	t->y = 128;
	t->v = 0;
	t->o = 0;
	t->fd = open(argv[2], O_RDONLY);
}

char	**norm2_norm_invers(t_norm6 *t, char *test, char **test2)
{
	test2 = (char **)malloc(sizeof(char*) * 100000);
	while (t->o < 100000)
	{
		test2[t->o] = (char *)malloc(sizeof(char) * 500);
		t->o++;
	}
	t->o = 0;
	while (t->o < 300000)
	{
		if (test[t->o] == '*')
		{
			test2[t->v][t->q] = '\0';
			t->o++;
			t->v++;
			t->q = 0;
		}
		test2[t->v][t->q] = test[t->o];
		t->q++;
		t->o++;
	}
	return (test2);
}
