#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
#define PSIZE getpagesize()

char	*tiny;
char	*small;
char	*large;







#endif
