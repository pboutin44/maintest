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

float   *point(char *objet);
void	ft_putnbr(int n);

enum
{
   STBI_default = 0, // only used for req_comp

   STBI_grey       = 1,
   STBI_grey_alpha = 2,
   STBI_rgb        = 3,
   STBI_rgb_alpha  = 4
};

typedef unsigned char stbi_uc;
typedef unsigned short stbi_us;
#define STBIDEF extern

/*typedef struct
{
   int	(*read)	(void *user,char *data,int size);
   void	(*skip)	(void *user,int n);
   int	(*eof)	(void *user);
} stbi_io_callbacks;
*/
char	**ft_strsplit(char const *s, char c);
void	my_putchar(char	c);
char	*get_next_line(const int fd);
float	*matrix_y(float teta, float x);
float   *produit_matricielle4(float mat1[], float mat2[], float teta);
float   *rotation_y(float mat1[], float mat2[], float teta);


#endif
