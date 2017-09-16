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

/*typedef struct			s_tiny
{
	void				*addr;
	size_t				size;
//	t_bool				tab[128];
	struct s_tiny		*next;
}						t_tiny;
*/

typedef struct      s_list
{
    char            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;


/*typedef struct			s_small
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
}						t_large;*/

typedef struct			s_malloc
{
	t_list				*tiny;
	t_list				*small;
	t_list				*large;
}						t_malloc;

	void	*ft_malloc(size_t size);
	void	*ft_memcpy(void	*dst, const void	*src, size_t n);
	t_list	*ft_lstnew(void const	*content, size_t	content_size);
	t_list	*browse_lst(t_list	*lst);
	t_list	*ft_lstiter(t_list	*lst, int	(f)(t_list	*elem));
	void	*size_tiny(size_t	size);
	void	*tiny_exist(size_t size);
	void	*another_tiny(size_t size);
	void	*first_tiny(size_t size);
	int		one_place_atleast(t_list	*elem);
	int		set_tinyheader(t_list	*lst);
	int		set_smallheader(t_list	*lst);
	void	*another_small(size_t	size);
	void	*first_small(size_t	size);
	void	*small_exist(size_t	size);
	void	*size_small(size_t	size);
	int		one_place_atleastsmall(t_list	*elem);
	void	*large_size(size_t	size);
	void	ft_free(void	*ptr);


t_malloc				zone;

#endif
