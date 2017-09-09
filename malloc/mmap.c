#include "malloc.h"

//void	*titi;

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	char	c;
	char	*str;
	int		nbr;

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
	printf("%s\n%d", str, nbr);
//	char toufe = "ecjhfhc";
	tiny = "pierro";
	printf("adresse:***** %p__%s **** %p__%s ****", str, str, str + 1, str + 1);
	printf("&&&&&&&&&%s&&&&&&&&&&&&%lu, %d", tiny, sizeof(tiny), PSIZE);
	if(tiny)
	{
		putchar('>');
	}
	if(small)
	{
		putchar('<');
	}
	
	return(0);
}

void	browse_free_place(void	*)
{

}

void	992_size()
{
	if(tiny)
	{
		
	}
	else
	{

	}

}

void	127000_size()
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

}

void	*choose_memory_adress(size_t size)
{
	if(size < 992)
	{
		return(992_size());
	}
	else if(size < 127000)
	{
		return(127000_size());
	}
	else
	{
		return(maxi_size());
	}
}

