#include "malloc.h"


int     set_tinyheader(t_list   *lst)
{
	int     i;

	i = 1;
	lst->content[0] = TRUE;
	while(i < 128)
	{
		lst->content[i] = FALSE;
		i++;
	}
	return(1);
}

void    *first_tiny(size_t size)
{
    void    *str;
    int     f;

    str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        zone.tiny = ft_lstnew(str, PSIZE * 2);
        f = set_tinyheader(zone.tiny);
        return(str + 127);
    }
}

void    *another_tiny(size_t size)
{
    void    *str;
    int     f;
    t_list  *lst;
    t_list  *lst2;

    str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.tiny);
        lst = ft_lstnew(str, PSIZE * 2);
        f = set_tinyheader(lst);
        lst2->next = lst;
        return(lst->content + 127);
    }
}

void    *tiny_exist(size_t size)
{
    t_list      *lst;
    int         i;
    void        *str;

    i = 0;
    lst = ft_lstiter(zone.tiny, one_place_atleast);
    if(lst == NULL)
    {
        str = another_tiny(size);

    }
    while(i < 126)
    {
        if(lst->content[i] == FALSE)
        {
            printf("&&&&%d&&&&", i);
            zone.tiny->content[i] = TRUE;
            return(lst->content + (127 + (64 * i)));
        }
        i++;
    }

    return(lst->content);
}

void	*size_tiny(size_t size)
{
	if(zone.tiny)
	{
		printf("1\n");
		return(tiny_exist(size));
	}
	else
	{
		printf("2\n");
		return(first_tiny(size));
	}
}
