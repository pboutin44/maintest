#include "malloc.h"

int	main(int argc, char **argv)
{
	fflush(stdout);
	char	*tiny;
	int		i;
	int		nb;
	char	c;
	char	*str;
	int		nbr;

	char	*test;
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	void	*test6;

	if(zone.tiny)
		putchar('<');
	else
		putchar('>');
	test = ft_malloc(10);
	test1 = ft_malloc(10);
	test2 = ft_malloc(10);
	test3 = ft_malloc(4000);
	test4 = ft_malloc(5000);
	test5 = ft_malloc(6000);
	test6 = ft_malloc(3000);
	printf("**y*%c****%p***%c**%p", test[0], test, test1[0], test1);
	printf("\n**y*%c****%p**", test5[0], test5);
	putchar('\n');
	ft_free(test5);
	ft_free(test2);
	ft_free(test1);
	ft_free(test);

	
	return(0);
}


int		one_place_atleast(t_list	*elem)
{
	int		i;

	i = 0;
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

int		one_place_atleastsmall(t_list	*elem)
{
	int		i;

	i = 0;
	while(i < 100)
	{
		if(elem->content[i] == FALSE)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

void	*ft_malloc(size_t size)
{
	if(size <= 0)
		return(NULL);
	if(size < 64)
	{
		return(size_tiny(size));
	}
	else if(size < 4096)
	{
		return(size_small(size));
	}
	else
	{
		return(large_size(size));
//		return(0);
	}
}

t_list		*find_browselarge(void	*ptr)
{

   t_list  *tmp;

	tmp = zone.large;
	while(tmp)
	{
		if(tmp->content == ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}

t_list		*find_browsetiny(void	*ptr)
{

   t_list  *tmp;

	tmp = zone.tiny;
	while(tmp)
	{
		if(tmp->content <= (char *)ptr && tmp->content + 2 * PSIZE >= (char *)ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}

t_list		*find_browsesmall(void	*ptr)
{

   t_list  *tmp;

	tmp = zone.small;
	while(tmp)
	{
		if(tmp->content <= (char *)ptr && tmp->content + 101 * PSIZE >= (char *)ptr)
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);	
}
void		free_tiny(void		*ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while(i < 64)
	{
		str[i] = 0;
		i++;
	}
}

void		ft_free(void	*ptr)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 0;
	lst = find_browselarge(ptr);
	if(lst)
	{
//		printf("***\n\n\n\n****");
		printf("\n**y*%s****%p**", lst->content, lst->content);
		munmap(lst->content, lst->content_size);
		
	}
	else if(find_browsesmall(ptr))
	{
		lst = find_browsesmall(ptr);


	}
	else if(find_browsetiny(ptr))
	{
		printf("lapere\n");
		lst = find_browsetiny(ptr);
		j = 128;
		while(i < 126)
		{
//		printf("%p___***___%p\n", ptr, lst->content + j);
			if(ptr == lst->content + j)
			{
				free_tiny(ptr);
				printf("ok__%d\n", j);

			}
			j = j + 64;
			i++;
		}

	}
	else
	{
	}



}


