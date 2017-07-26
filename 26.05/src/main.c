/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/26 19:09:18 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

int			norm_vbo(t_norm3 *n)
{
	glGenBuffers(1, &n->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, n->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 56880,
			n->str65, GL_STATIC_DRAW);
	glGenBuffers(1, &n->colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, n->colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 56880,
			n->colours, GL_STATIC_DRAW);
	norm_norm_vbo(n);
	glBindBuffer(GL_ARRAY_BUFFER, n->vt_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 56880,
			n->texcoords, GL_STATIC_DRAW);
	glGenVertexArrays(1, &n->vao);
	glBindVertexArray(n->vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, n->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, n->colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, n->vt_vbo);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	return (1);
}

t_norm3		norm_init(t_norm3 n)
{
	n.t = 0;
	n.colours_vbo = 0;
	n.tex = 0;
	n.str65 = (float *)malloc(56880 * sizeof(float));
	n.colours = (float *)malloc(56880 * sizeof(float));
	n.texcoords = (float *)malloc(56880 * sizeof(float));
	n.view_mat = view_norm();
	n.proj_mat = proj_norm();
	n.window = NULL;
	n.matrix = norm_matrix(n.matrix);
	n.matrix6 = norm_matrix6(n.matrix6);
	n.matrix7 = norm_matrix7(n.matrix7);
	n.matrix1 = norm_matrix1(n.matrix1);
	n.matrix2 = norm_matrix2(n.matrix2);
	n.matrix3 = produit_matricielle4(n.matrix, n.matrix1, 1.0);
	n.x = 128;
	n.y = 128;
	return (n);
}

void		norm_init2(t_norm3 *n)
{
	while (n->str56[n->h] != 88888888)
	{
		n->h++;
	}
	n->nb_tr = 56900;
	n->l = 0.0;
	if (n->h < 56820)
	{
		n->l = 0.5;
		n->nb_tr = 77;
	}
	n->matrix8 = (float *)malloc(16 * sizeof(float));
	n->matrix8 = matrix_y(0, n->l);
	n->d = 0;
	n->m = 0;
	while (n->str56[n->d] != 88888888)
	{
		n->str65[n->d] = n->str56[n->d];
		n->texcoords[n->m] = n->str56[n->d];
		n->m++;
		n->d++;
	}
}

void		norm3(t_norm3 *n)
{
	n->vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(n->vs, 1, &n->vertex_shader, NULL);
	glCompileShader(n->vs);
	n->fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(n->fs, 1, &n->fragment_shader, NULL);
	glCompileShader(n->fs);
	n->shader_programme = glCreateProgram();
	glAttachShader(n->shader_programme, n->fs);
	glAttachShader(n->shader_programme, n->vs);
	glLinkProgram(n->shader_programme);
	glUseProgram(n->shader_programme);
	n->matrix_location = glGetUniformLocation(n->shader_programme, "matrix8");
	glUniformMatrix4fv(n->matrix_location, 1, GL_FALSE, n->matrix8);
	n->view_mat_location = glGetUniformLocation(n->shader_programme, "view");
	glUseProgram(n->shader_programme);
	glUniformMatrix4fv(n->view_mat_location, 1, GL_FALSE, n->view_mat);
	n->proj_mat_location = glGetUniformLocation(n->shader_programme, "proj");
	glUseProgram(n->shader_programme);
	glUniformMatrix4fv(n->proj_mat_location, 1, GL_FALSE, n->proj_mat);
	n->tex_loc = glGetUniformLocation(n->shader_programme, "basic_texture");
	glUseProgram(n->shader_programme);
	glUniform1i(n->tex_loc, 0);
}

int			main(int argc, char *argv[])
{
	t_norm3		n;
	int			fd;
	char		*str;
	
	if(argc != 3)
		return (0);
	n = norm_init(n);
	n.str56 = point(argv[1]);
	norm_init2(&n);
	norm_color_table(n.str56, n.colours);
	n.testto = norm_invers(argv);
	n.window = norm_windows(n.window);
	norm_vbo(&n);
	n.vertex_shader = vertex();
	n.fragment_shader = fragment();
	norm3(&n);
	norm_loop(n.textura, &n);
	glfwTerminate();
	return (0);
}
