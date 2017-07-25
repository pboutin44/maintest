/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 18:08:46 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_H
# define SCOPE_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define MEM_SIZE 4096
# define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0
# define WIDTH 1640
# define HEIGHT 1480

float				*point(char *objet);
void				ft_putnbr(int n);

typedef	struct		s_norm1
{
	int				i;
	int				j;
	int				k;
	int				l;

}					t_norm1;

typedef	struct		s_norm2
{
	int				fd;
	char			*str;
	char			**str1;
	char			**str2;
	char			**str2bis;
	char			**str_tmp;
	char			**str_tmp2;
	char			*str3;

}					t_norm2;

typedef	struct		s_norm3
{
	GLFWwindow		*window;
	GLuint			vao;
	GLuint			vbo;
	bool			textura;
	float			*matrix;
	float			*matrix6;
	float			*matrix7;
	float			*matrix1;
	float			*matrix2;
	float			*matrix3;
	float			l;
	int				nb_tr;
	float			*str56;
	float			*str65;
	float			*texcoords;
	float			*colours;
	int				h;
	int				d;
	float			*matrix8;
	int				m;
	int				a;
	int				matrix_location;
	int				view_mat_location;
	int				proj_mat_location;
	int				tex_loc;
	float			*view_mat;
	float			*proj_mat;
	int				i;
	int				x;
	int				y;
	int				n;
	int				fd;
	int				t;
	int				w;
	unsigned char	*testto;
	GLuint			vs;
	GLuint			fs;
	GLuint			shader_programme;
	GLuint			uniformid;
	const char		*fragment_shader;
	const char		*vertex_shader;
	GLuint			colours_vbo;
	GLuint			tex;
	GLuint			vt_vbo;
}					t_norm3;

typedef	struct		s_norm4
{
	float			teta;
	float			speed;
	float			last_position;
	float			last1_position;
	float			last2_position;
	double			previous_seconds;
	double			current_seconds;
	double			elapsed_seconds;
	double			elapsed1_seconds;
	double			elapsed2_seconds;
	double			elapsed3_seconds;
}					t_norm4;

typedef struct		s_norm5
{
	float			near;
	float			far;
	float			fov;
	float			aspect;
	float			range;
	float			sx;
	float			sy;
	float			sz;
	float			pz;
	float			*proj_mat;
}					t_norm5;

typedef struct		s_norm6
{
	int				width_in_bytes;
	int				half_height;
	int				x;
	int				y;
	int				o;
	int				fd;
	int				q;
	int				v;
}					t_norm6;

typedef	struct		s_norm7
{
	unsigned char	*top;
	unsigned char	*bottom;
	unsigned char	temp;
	unsigned char	*testto;
	int				row;
	int				col;
}					t_norm7;

typedef	struct		s_norm8
{
	int				i;
	int				flag;
	char			*str;
	char			**str1;
}					t_norm8;

char				**ft_strsplit(char const *s, char c);
void				my_putchar(char	c);
void				my_putstr(char *str);
char				*get_next_line(const int fd);
float				*matrix_y(float teta, float x);
float				*produit_matricielle4(float mat1[], float mat2[],
					float teta);
float				*rotation_y(float mat1[], float mat2[], float teta);

float				*points_norm(char **str2bis, char **str_tmp2,
					char **str_tmp, char **str1);
char				**points_norm1(char **str_tmp, char **str2);
char				**points_norm2(int fd);
char				**points_norm3(int fd);

float				*norm_matrix(float *matrix);
float				*norm_matrix6(float *matrix6);
float				*norm_matrix7(float *matrix7);
float				*norm_matrix1(float *matrix1);
float				*norm_matrix2(float *matrix2);

float				*proj_norm(void);
float				*view_norm(void);
void				norm_norm_loop(t_norm3 *n, t_norm4 *t);
void				norm_color_table(float *str56, float *colours);
float				colours_norm(int d, float e);
void				my_putnbr(int n);

void				norm2_norm_loop(t_norm3 *n, t_norm4 *t);
void				norm3_norm_loop(t_norm3 *n, t_norm4 *t);
void				norm_norm4_norm_loop(t_norm3 *n, t_norm4 *t);

void				norm_loop(int textura, t_norm3 *n);
void				norm_norm_invers(t_norm6 *t, t_norm7 *u, char **argv);
char				**norm2_norm_invers(t_norm6 *t, char *test, char **test2);

void				norm_norm_vbo(t_norm3 *n);
GLFWwindow			*norm_windows(GLFWwindow *window);
unsigned char		*norm_invers(char **argv);

char				*vertex(void);
char				*fragment(void);

int					my_strlen(char *str);
int					words_number(char const *s, char c);
int					words_size(char const *s, char c, int i);

char				*add_to_line(char *line, int treat, char *buff, int *start);
char				*my_strncpy(char *dest, char *src, int n);
int					my_put_nbr(int n);
char				**ft_strsplit(char const *s, char c);
char				**new_tab(char const *s, char c, int result);

char				*ft_strcat(char *s1, const char *s2);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*get_next_line(const int fd);

float				*point(char *objet);
void				init_points_norm3(t_norm8 *t);
char				**points_norm3(int fd);
char				**points_norm2_norm(int fd, char **str2, int flag);
char				**points_norm2(int fd);

char				**points_norm1_norm_norm(char **str2, char **str2bis,
					t_norm1 var, char **str_tmp);
#endif
