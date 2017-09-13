#include "malloc.h"

//void	*titi;

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t          i;
    const char      *src1;
    char            *dst1;

    i = 0;
    src1 = src;
    dst1 = dst;
    while (i < n)
    {
        dst1[i] = src1[i];
        i++;
    }
    return (dst1);
}

 t_list  *ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

//	if (!(new = (t_list *)malloc(sizeof(t_list))))
	if (!(new = (t_list *)mmap(0, sizeof(t_list), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
//		if (!(new->content = malloc(sizeof(new->content) * content_size)))
/*		if (!(new->content = mmap(0, sizeof(new->content) * content_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		ft_memcpy(new->content, (void *)content, content_size);*/
		new->content = (char *)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	fflush(stdout);
	char	*tiny;
	int		i;
	int		nb;
	char	c;
	char	*str;
	int		nbr;
	//t_malloc	zone;

//	zone.tiny = ft_lstnew(NULL, 0);

	nb = atoi(argv[2]);
	c = argv[1][0];
	nbr = getpagesize();
	str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while(i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
/*	printf("%s\n%d", str, nbr);
//	char toufe = "ecjhfhc";
	tiny = "pierro";
	printf("adresse:***** %p__%s **** %p__%s ****", str, str, str + 1, str + 1);
	printf("&&&&&&&&&%s&&&&&&&&&&&&%lu, %d", tiny, sizeof(tiny), PSIZE);*/
/*	if(tiny)
	{
		putchar('>');
	}
	if(tiny)
	{
		putchar('<');
	}*/
//	zone.tiny = ft_lstnew(NULL, 0);
	char	*test;
	char	*test1;
	if(zone.tiny)
		putchar('<');
	else
		putchar('>');
	test = choose_memory_adress(10);
		putchar('p');
	test1 = choose_memory_adress(10);
	printf("***%c****%p*****%p", zone.tiny->content[0], test, test1);

	
	return(0);
}

/*void	browse_free_place(void	*)
{

}*/
int		set_tinyheader()
{
	int		i;
	i = 0;
	
		printf("\ntest46bis");
	while(i < 128)
	{
	//	printf("o");
		zone.tiny->content[i] = FALSE;
		i++;
	}
		printf("\ntest46bis2");
	return(1);
//		printf("\nppppp__%c__ppppp%p", zone.tiny->content[0], zone.tiny->content);
}

void	*first_tiny(size_t size)
{
	void	*str;
	int		f;
	
	printf("\neerferf");
	str = mmap(0, PSIZE * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if(str == MAP_FAILED)
	{
		printf("error MAP_FAILED");
		return(NULL);
	}
	else
	{
		printf("\ntest45");
		zone.tiny = ft_lstnew(str, PSIZE * 2);
		printf("\ntest46\n");

		f = set_tinyheader();
		printf("\ntest47%d\n", f);
		printf("adr TINY%p_____adr str%p___", zone.tiny->content, str);
		return(str + 128);
	}
}

int		one_place_atleast(t_list	*elem)
{
	int		i;
	i = 0;
	putchar('#');
	printf("}}}}%p}}}\n", elem->content);
	while(i < 126)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

t_list	*ft_lstiter(t_list *lst, int (f)(t_list *elem))
{
	t_list	*tmp;
		putchar('#');
	
	if(lst && f)
	{
		tmp = lst;
		putchar('$');
		printf("oier___%p___%p\n", tmp, lst);
		while(tmp)
		{
		putchar('$');
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

void	*tiny_exist(size_t size)
{
	t_list		*lst;
	printf("TINY%p", zone.tiny);
	lst = ft_lstiter(zone.tiny, one_place_atleast);
	printf("!!!!!!!!! ->> %d\n", (unsigned int)lst);
	return(lst->content);
}

void	*size_tiny(size_t size)
{
	putchar('g');
	if(zone.tiny)
	{
		return(tiny_exist(size));
	}
	else
	{
		printf("\nfdd");
//		printf("mais pourquoi tant de haine");
		return(first_tiny(size));
	}
}

/*void	4096_size()
{
	if(small)
	{
	}
	else
	{
	}
}

void	browse_large(void	*)
{

}*/

void	*choose_memory_adress(size_t size)
{
	if(size < 64)
	{
		return(size_tiny(size));
	}
	else if(size < 4096)
	{
//		return(4096_size());
		return(NULL);
	}
	else
	{
//		return(maxi_size());
		return(NULL);
	}
}

