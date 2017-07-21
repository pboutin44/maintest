#ifndef __include_scop_h__
#define __include_scop_h__

#include <GL/glew.h>   // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define MEM_SIZE 4096
#define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0
#define width 1640
#define height 1480

float   *point(char *objet);
void	ft_putnbr(int n);

typedef unsigned char stbi_uc;
typedef unsigned short stbi_us;
#define STBIDEF extern

typedef struct
{
	int	i;
	int	j;
	int	k;
	int	l;

} t_norm1;

typedef struct
{
	int		fd;
	char	*str;
	char	**str1;
	char	**str2;
	char	**str2bis;
	char	**str_tmp;
	char	**str_tmp2;
	char	*str3;

} t_norm2;

typedef struct
{
	GLFWwindow	*window;
	GLuint		vao;
	GLuint		vbo;
	bool		textura;
	float	*matrix;
	float   *matrix6;
	float   *matrix7;
	float   *matrix1;
	float   *matrix2;
	float   *matrix3;
	float   l;
	int     nb_tr;
	float   *str56;
	float   *str65;
	float   *texcoords;
	float   *colours;
	int     h;
	int     d;
	float   *matrix8;
	int     m;
	int     a;
	int     matrix_location;
	int     view_mat_location;
	int     proj_mat_location;
	int     tex_loc;
	float   *view_mat;
	float   *proj_mat;
	int i;
	int x;
	int y;
	int n;
	int fd;
	int t;
	int w;
	unsigned char *testto;
	GLuint vs;
	GLuint  fs;
	GLuint shader_programme;
	GLuint uniformID;
	const char *fragment_shader;
	const char *vertex_shader;
	GLuint colours_vbo;
	GLuint tex;
	GLuint vt_vbo;
} t_norm3;

char	**ft_strsplit(char const *s, char c);
void	my_putchar(char	c);
char	*get_next_line(const int fd);
float	*matrix_y(float teta, float x);
float   *produit_matricielle4(float mat1[], float mat2[], float teta);
float   *rotation_y(float mat1[], float mat2[], float teta);

float   *points_norm(char   **str2bis, char **str_tmp2, char **str_tmp, char **str1);
char    **points_norm1(char **str_tmp, char **str2);
char    **points_norm2(int  fd);
char    **points_norm3(int fd);

#endif
