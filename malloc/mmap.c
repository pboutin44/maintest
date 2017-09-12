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
		if (!(new->content = mmap(0, sizeof(new->content) * content_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		ft_memcpy(new->content, (void *)content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
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
	if(zone.tiny)
		putchar('<');
	else
		putchar('>');
//	choose_memory_adress(10);
	
	return(0);
}

/*void	browse_free_place(void	*)
{

}*/
void	*first_tiny(size_t size)
{

}


void	*size_tiny(size_t size)
{
//	void	*test
	if(zone.tiny)
	{
//		return(test);	
	}
	else
	{
		first_tiny(size);	
	}
	return(NULL);
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

