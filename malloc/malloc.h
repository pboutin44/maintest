#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
#define PSIZE getpagesize()
# define TRUE '1'
# define FALSE '0'
typedef char			t_bool;

typedef struct			s_tiny
{
	void				*addr;
	size_t				size;
//	t_bool				tab[128];
	struct s_tiny		*next;
}						t_tiny;


typedef struct      s_list
{
    char            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;


typedef struct			s_small
{
	void				*addr;
	size_t				size;
	t_bool				tab[100];
	struct s_small		*next;
}						t_small;

typedef	struct			s_large
{
	void				*addr;
	size_t				size;
	struct	s_large		*next;
}						t_large;

typedef struct			s_malloc
{
	t_list				*tiny;
	t_small				*small;
	char				*large;
}						t_malloc;
	void	*choose_memory_adress(size_t size);

extern	t_malloc		zone1;
t_malloc				zone;
extern	int				test;
int		test2;
#endif
