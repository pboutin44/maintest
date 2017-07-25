/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 15:22:33 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			norm3_norm_invers(t_norm6 *t, t_norm7 *u, char **test2)
{
	u->testto = (unsigned char *)malloc(sizeof(unsigned char) * 100000);
	t->o = 0;
	while (t->o < 100000)
	{
		u->testto[t->o] = ((unsigned char)atoi(test2[t->o]));
		t->o++;
	}
}

void			norm4_norm_invers(t_norm6 *t, t_norm7 *u)
{
	while (u->row < t->half_height)
	{
		u->top = u->testto + u->row * t->width_in_bytes;
		u->bottom = u->testto + (t->y - u->row - 1) * t->width_in_bytes;
		u->col = 0;
		while (u->col < t->width_in_bytes)
		{
			u->temp = *u->top;
			*u->top = *u->bottom;
			*u->bottom = u->temp;
			u->top++;
			u->bottom++;
			u->col++;
		}
		u->row++;
	}
}

unsigned char	*norm_invers(char **argv)
{
	char		*test;
	char		**test2;
	t_norm6		t;
	t_norm7		u;

	u.row = 0;
	norm_norm_invers(&t, &u, argv);
	test = get_next_line(t.fd);
	test2 = norm2_norm_invers(&t, test, test2);
	norm3_norm_invers(&t, &u, test2);
	norm4_norm_invers(&t, &u);
	return (u.testto);
}

GLFWwindow		*norm_windows(GLFWwindow *window)
{
	const GLubyte *renderer;
	const GLubyte *version;

	if (!glfwInit())
		fprintf(stderr, "ERROR: could not start GLFW3\n");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	window = glfwCreateWindow(1640, 1480, "Hello Triangle", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	return (window);
}

void			norm_norm_vbo(t_norm3 *n)
{
	glGenTextures(1, &n->tex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, n->tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, n->x, n->y, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, n->testto);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glGenBuffers(1, &n->vt_vbo);
}
