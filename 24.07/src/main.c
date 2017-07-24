/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/24 18:04:05 by pboutin          ###   ########.fr       */
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

void		my_putnbr(int n)
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

float	colours_norm(int d, float e)
{
	float	colours;

			if((d + 1) % 3 == 1)
			{
				colours = e;
			}
			if((d + 1) % 3 == 2)
			{
				colours = e;
			}
			if((d + 1) % 3 == 0)
			{
				colours = e;
			}
			return(colours);

}

void	norm_color_table(float *str56, float *colours)
{
	int	d;
	int m;
	int a;

	d = 0;
	m = 0;
	a = 0;
	while(str56[d] != 88888888)
	{
		m++;
		if( a > 2)
		{
			a = 0;
		}
		if(a == 0)
			colours[d] = colours_norm(d, 0.1);
		else if(a == 1)
			colours[d] = colours_norm(d, 0.15);
		else if(a == 2)
			colours[d] = colours_norm(d, 0.2);
		if((d + 1) % 9 == 0)
			a++;
		d++;
	}
}
void	norm_norm_loop(t_norm3 *n, t_norm4 *t)
{
		if (glfwGetKey (n->window, GLFW_KEY_EQUAL)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
			t->last2_position = n->matrix7[14];
			t->teta = t->teta + 0.01;
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
		if (glfwGetKey (n->window, GLFW_KEY_RIGHT)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position + 0.01f;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme); 
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}

}

void	norm2_norm_loop(t_norm3 *n, t_norm4 *t)
{
		if (glfwGetKey (n->window, GLFW_KEY_LEFT)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position - 0.01f; 
			t->last_position = n->matrix7[12]; 
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position; 
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
		if (glfwGetKey (n->window, GLFW_KEY_UP)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position + 0.01f;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
}

void	norm3_norm_loop(t_norm3 *n, t_norm4 *t)
{
		if (glfwGetKey (n->window, GLFW_KEY_DOWN)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position - 0.01f;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
		if (glfwGetKey (n->window, GLFW_KEY_SPACE)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position + 0.01f;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
}

void	norm4_norm_loop(t_norm3 *n, t_norm4 *t)
{
		if (glfwGetKey (n->window, GLFW_KEY_M)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position - 0.01f;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
		if (glfwGetKey (n->window, GLFW_KEY_M)) {
			n->matrix7[12] = t->elapsed_seconds * t->speed + t->last_position;
			t->last_position = n->matrix7[12];
			n->matrix7[13] = t->elapsed1_seconds * t->speed + t->last1_position;
			t->last1_position = n->matrix7[13];
			n->matrix7[14] = t->elapsed2_seconds * t->speed + t->last2_position - 0.01f;
			t->last2_position = n->matrix7[14];
			n->matrix8 = matrix_y(t->teta, n->l);
		   	n->matrix3 = produit_matricielle4(n->matrix7, n->matrix8, 56);
			glUseProgram (n->shader_programme);
			glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix3);
		}
}

void	norm5_norm_loop(t_norm3 *n)
{
		if (glfwGetKey (n->window, GLFW_KEY_N)) {
			n->textura = 1;
			n->uniformID  = glGetUniformLocation(n->shader_programme, "textura");
			glUseProgram(n->shader_programme);
			glUniform1f(n->uniformID, n->textura);
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
	t_norm4	t;

	t.teta = 0;
	t.speed = 1.0f;
	t.last_position = 0.0f;
	t.last1_position = 0.0f;
	t.last2_position = 0.0f;
	while (!glfwWindowShouldClose(n->window)) {
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

t_norm5		norm_proj_norm()
{
	t_norm5	p;

	p.near = 0.1f;
	p.far = 100.0f;
	p.fov = 67.0f * ONE_DEG_IN_RAD;
	p.aspect = (float)width / (float)height;
	p.range = tan (p.fov * 0.5f) * p.near;
	p.Sx = (2.0f * p.near) / (p.range * p.aspect + p.range * p.aspect);
	p.Sy = p.near / p.range;
	p.Sz = -(p.far + p.near) / (p.far - p.near);
	p.Pz = -(2.0f * p.far * p.near) / (p.far - p.near);
	return(p);
}


float	*proj_norm()
{
	t_norm5 p;

	p = norm_proj_norm();
	p.proj_mat = (float *)malloc(sizeof(float) * 16);
	p.proj_mat[0] = p.Sx;
	p.proj_mat[1] = 0.0f;
	p.proj_mat[2] = 0.0f;
	p.proj_mat[3] = 0.0f;
	p.proj_mat[4] = 0.0f;
	p.proj_mat[5] = p.Sy;
	p.proj_mat[6] = 0.0f;
	p.proj_mat[7] = 0.0f;
	p.proj_mat[8] = 0.0f;
	p.proj_mat[9] = 0.0f;
	p.proj_mat[10] = p.Sz;
	p.proj_mat[11] = -1.0f;
	p.proj_mat[12] = 0.0f;
	p.proj_mat[13] = 0.0f;
	p.proj_mat[14] = p.Pz;
	p.proj_mat[15] = 0.0f;
	return(p.proj_mat);
}

float	*view_norm()
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
	return(view_mat);
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
	t->fd = open(argv[3], O_RDONLY);
}

char	**norm2_norm_invers(t_norm6 *t, char *test, char **test2)
{
	test2 = (char **)malloc(sizeof(char*) * 100000);
	while(t->o < 100000)
	{
		test2[t->o] = (char *)malloc(sizeof(char) * 500);
		t->o++;
	}
	t->o = 0;
	while(t->o < 300000)
	{
		if(test[t->o] == '*')
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
	return(test2);
}

void	norm3_norm_invers(t_norm6 *t, t_norm7 *u, char **test2)
{
	u->testto = (unsigned char *)malloc(sizeof(unsigned char) * 100000);
	t->o = 0;
	while(t->o < 100000)
	{
		u->testto[t->o] = ((unsigned char)atoi(test2[t->o]));
		t->o++;
	}
}


unsigned char	*norm_invers(char	**argv)
{
	char	*test;
	char	**test2;
	t_norm6	t;
	t_norm7 u;

	norm_norm_invers(&t, &u, argv);
	test = get_next_line(t.fd);
	test2 = norm2_norm_invers(&t, test, test2);
	norm3_norm_invers(&t, &u, test2);
	/*u.testto = (unsigned char *)malloc(sizeof(unsigned char) * 100000);
	t.o = 0;
	while(t.o < 100000)
	{
		u.testto[t.o] = ((unsigned char)atoi(test2[t.o]));
		t.o++;
	}*/
         for (int row = 0; row < t.half_height; row++) {
             u.top = u.testto + row * t.width_in_bytes;
             u.bottom = u.testto + (t.y - row - 1) * t.width_in_bytes;
             for (int col = 0; col < t.width_in_bytes; col++) {
                 u.temp = *u.top;
                 *u.top = *u.bottom;
                 *u.bottom = u.temp;
                 u.top++;
                 u.bottom++;
             }
         }
		 return(u.testto);
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
	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	return(window);
}

int		norm_vbo(GLuint *vbo, float	*str65, GLuint *colours_vbo, float *colours, GLuint *tex, int x, int y, unsigned char *testto, GLuint *vt_vbo, float *texcoords, GLuint *vao)
{
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER,  sizeof(float) * 56880, str65, GL_STATIC_DRAW);
	glGenBuffers (1, colours_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, *colours_vbo);
	glBufferData (GL_ARRAY_BUFFER, sizeof (float) * 56880, colours, GL_STATIC_DRAW);
	glGenTextures (1, tex);
	glActiveTexture (GL_TEXTURE0);
	glBindTexture (GL_TEXTURE_2D, *tex);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, testto);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glGenBuffers (1, vt_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, *vt_vbo);
	glBufferData (GL_ARRAY_BUFFER, sizeof(float) * 56880, texcoords, GL_STATIC_DRAW );
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer (GL_ARRAY_BUFFER, *colours_vbo);
	glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer (GL_ARRAY_BUFFER, *vt_vbo);
	glVertexAttribPointer (2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray (2);
	glEnableVertexAttribArray (0);
	glEnableVertexAttribArray (1);
	return(1);
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
	return(n);
}

void		norm_init2(t_norm3	*n)
{
	while(n->str56[n->h] != 88888888)
	{
		n->h++;
	}
		n->nb_tr = 56900;
		n->l = 0.0;

	if(n->h < 56820)
	{
		n->l = 0.5;
		n->nb_tr = 77;
	}
	n->matrix8 = (float *)malloc(16 * sizeof(float));
	n->matrix8 = matrix_y( 0, n->l);
	n->d = 0;
	n->m = 0;

	while(n->str56[n->d] != 88888888)
	{
		n->str65[n->d] = n->str56[n->d];
		n->texcoords[n->m] = n->str56[n->d];
		n->m++;
		n->d++;
	}
}

void	norm3(t_norm3	*n)
{
	n->vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(n->vs, 1, &n->vertex_shader, NULL);
	glCompileShader(n->vs);
	n->fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(n->fs, 1, &n->fragment_shader, NULL);
	glCompileShader(n->fs);
	n->shader_programme = glCreateProgram();
	glAttachShader( n->shader_programme, n->fs);
	glAttachShader(n->shader_programme, n->vs);
	glLinkProgram(n->shader_programme);
	glUseProgram (n->shader_programme);
	n->matrix_location = glGetUniformLocation (n->shader_programme, "matrix8");
	glUniformMatrix4fv (n->matrix_location, 1, GL_FALSE, n->matrix8);
	n->view_mat_location = glGetUniformLocation (n->shader_programme, "view");
	glUseProgram (n->shader_programme);
	glUniformMatrix4fv (n->view_mat_location, 1, GL_FALSE, n->view_mat);
	n->proj_mat_location = glGetUniformLocation (n->shader_programme, "proj");
	glUseProgram (n->shader_programme);
	glUniformMatrix4fv (n->proj_mat_location, 1, GL_FALSE, n->proj_mat);
	n->tex_loc = glGetUniformLocation (n->shader_programme, "basic_texture");
	glUseProgram (n->shader_programme);
	glUniform1i (n->tex_loc, 0);
}

char	*vertex()
{
	char	*str;

	str = "#version 330\nlayout(location = 0) in vec3 vp;layout(location = 1) in vec3 vc;layout(location = 2) in vec2 vt;out vec2 texture_coordinates;uniform mat4 matrix;uniform mat4 matrix8, view, proj;out vec3 colour;void main () {texture_coordinates = vt;colour = vc;gl_Position = proj * view * matrix8 * vec4 (vp, 2.0);}";
	return(str);
}

char	*fragment()
{
	char	*str;

	str = "#version 330\nin vec3 colour;out vec4 frag_colour;in vec2 texture_coordinates;uniform sampler2D basic_texture;uniform bool textura;void main () {vec4 texel = texture (basic_texture, texture_coordinates);frag_colour =  vec4 (colour, 1.0);if(textura){frag_colour = texel;}}";
	return(str);
}


int	main(int argc, char *argv[]){
	t_norm3		n;
	int			fd;
	char		*str;

	n = norm_init(n);
	n.str56 = point(argv[1]);
	norm_init2(&n);
	norm_color_table(n.str56, n.colours);
	n.testto = norm_invers(argv);
	n.window = norm_windows(n.window);
	norm_vbo(&n.vbo, n.str65, &n.colours_vbo, n.colours, &n.tex, 
			n.x, n.y, n.testto, &n.vt_vbo, n.texcoords, &n.vao);
	n.vertex_shader = vertex();
	n.fragment_shader = fragment();
	norm3(&n);
//void	norm_loop(float *matrix7, float *matrix8, float *matrix3, GLuint shader_programme, int	matrix_location, GLuint vao, GLFWwindow *window, int nb_tr, float l, GLuint uniformID, int textura, t_norm3 *n)
	norm_loop(n.textura, &n);
	glfwTerminate();
	return (0);
}
