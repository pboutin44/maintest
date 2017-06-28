#ifndef __include_scop_h__
#define __include_scop_h__

#include <GL/glew.h>   // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

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

typedef struct
{
   int	(*read)	(void *user,char *data,int size);
   void	(*skip)	(void *user,int n);
   int	(*eof)	(void *user);
} stbi_io_callbacks;


float	*matrix_y(float teta, float x);
float   *produit_matricielle4(float mat1[], float mat2[], float teta);
float   *rotation_y(float mat1[], float mat2[], float teta);
stbi_uc *stbi_load	(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
stbi_uc *stbi_load_from_memory   (stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
stbi_uc *stbi_load_from_callbacks(stbi_io_callbacks const *clbk , void *user, int *x, int *y, int *channels_in_file, int desired_channels);
stbi_uc *stbi_load_from_file   (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
float *stbi_loadf	(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
float *stbi_loadf_from_memory	(stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
float *stbi_loadf_from_callbacks	(stbi_io_callbacks const *clbk, void *user, int *x, int *y,  int *channels_in_file, int desired_channels);
float *stbi_loadf_from_file	(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
int		stbi_is_hdr	(char const *filename);
int		stbi_is_hdr_from_file(FILE *f);
int		stbi_info(char const *filename,	int *x, int *y, int *comp);
int		stbi_info_from_file(FILE *f, int *x, int *y, int *comp);


#endif
