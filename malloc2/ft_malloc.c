/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:37:51 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/27 20:07:15 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"
int		globale;

int		main(void)
{
	char	*test;
	char	*test2;
	void	*test3;
	void	*test4;
	void	*tab[200];
	int		i;

	i = 0;
	while(i < 200)
	{
		tab[i] = (char *)ft_malloc(900);
		i++;
	}
	test = (char *)ft_malloc(6000);
	test2 = (char *)ft_malloc(60000);
//	test3 = (char *)ft_malloc(900);
//	test4 = (char *)ft_malloc(900);
	show_alloc_mem();
	printf("globale: %d", globale);
	return (0);
}

int     set_smallheader(t_list  *lst)
{
	int     i;

	i = 26;
	lst->content[25] = TRUE;
	while(i < 125)
	{
		lst->content[i] = FALSE;
		i++;
	}
	return(1);
}


t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)content))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (char *)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

void		*first_large(size_t	size)
{
	void	*str;
	int		f;
	int		nb;

	printf("first_large");
	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return (NULL);
	}
	else
	{
		zone.large = ft_lstnew(str, PSIZE * nb);
		return (str);
	}
}

t_list		*browse_lst(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (NULL);
}

void	browse_lst2(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			printf("\nadresse %p-%p: %zu %lu", lst->content, lst->content + lst->content_size, lst->content_size, sizeof(t_list));
			lst = lst->next;
		}
			printf("\nadresse %p-%p: %zu", lst->content, lst->content + lst->content_size, lst->content_size);
	}
}

void		*already_large(size_t	size)
{
	void	*str;
	int		f;
	t_list	*lst;
	t_list	*lst2;
	int		nb;

	printf("NOTfirst_large");
	nb = size / PSIZE;
	nb = nb + 2;
	str = mmap(0, PSIZE * nb, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return (NULL);
	}
	else
	{
		lst2 = browse_lst(zone.large);
		lst = ft_lstnew(str, PSIZE * nb);
		lst2->next = lst;
		return (lst->content + 25);
	}
}

void	show_alloc_mem(void)
{
	browse_lst2(zone.tiny);
	printf("\nsmall");
	browse_lst2(zone.small);
	printf("\nlarge");
	browse_lst2(zone.large);
}


int     one_place_atleastsmall(t_list   *elem)
{
	int		i;

	i = 25;
	while(i < 125)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

t_list  *ft_lstiter(t_list *lst, int (f)(t_list *elem))
{
    t_list  *tmp;

    if(lst && f)
    {
        tmp = lst;
        while(tmp)
        {
            if(f(tmp) == 1)
            {
                return(tmp);
            }
            tmp = tmp->next;
        }
    }
    printf("COUCOU JE RETOURNE NULL\n");
    return(NULL);
}


void    *another_small(size_t size)
{
    void    *str;
    int     f;
    t_list  *lst;
    t_list  *lst2;

    str = mmap(0, PSIZE * 101, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(str == MAP_FAILED)
    {
        printf("error MAP_FAILED");
        return(NULL);
    }
    else
    {
        lst2 = browse_lst(zone.small);
        lst = ft_lstnew(str, PSIZE * 101);
        f = set_smallheader(lst);
        lst2->next = lst;
        return(lst->content + 4095);
    }
}

void		*already_small(size_t size)
{
//	printf("_*");
	t_list		*lst;
	int			i;
	void		*str;

	i = 25;
	lst = ft_lstiter(zone.small, one_place_atleastsmall);
	if (lst == NULL)
	{
		globale++;
		printf("cacao");
		str = another_small(size);
		
		return(str);
	}
	while(i < 126)
	{
		if(lst->content[i] == FALSE)
		{
			printf("malboro, %d, %c", i, lst->content[i]);
			globale++;
	//		printf("light");
	//		printf("&&&&%d&&&&&", i);
			lst->content[i] = TRUE;
			return(lst->content + (4095 + (4096 * (i - 25))));
		}
		i++;
	}
	return(lst->content);
}

void		*first_small(size_t size)
{
			globale++;
	printf("firstsmall");
	void	*str;
	int		f;

	str = mmap(0, PSIZE * 101, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if(str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return(NULL);
	}
	else
	{
		zone.small = ft_lstnew(str, PSIZE * 101);
		f = set_smallheader(zone.small);
		return(str + 4095);
	}
}

void		*large(size_t size)
{
	if (zone.large)
		return (already_large(size));
	else
		return (first_large(size));
}

void		*small(size_t size)
{
	if (zone.small)
		return (already_small(size));
	else
		return (first_small(size));
}

void		*ft_malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	else if (size < 65)
		return (NULL/*tiny(size)*/);
	else if (size < 4097)
		return (small(size));
	else
		return (large(size));
}
