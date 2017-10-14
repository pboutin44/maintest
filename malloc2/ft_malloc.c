/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:37:51 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/15 00:18:34 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"

int		main(void)
{
	int	i;
	char	*addr;
	void	*str;

	i = 0;
	while(i < 50)
	{

		addr = (char *)ft_malloc(50);
		addr[0] = 42;
//		ft_free(addr);
		i++;
	}
	show_alloc_mem();
	return(0);
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
	int		i;

	i = 25;
	if (lst)
	{
		if(lst->next)
		{
			while (lst->next)
			{
				printf("\nadresse %p-%p: %zu %lu", lst->content, lst->content + lst->content_size, lst->content_size, sizeof(t_list));
				i = 25;
				while(i < 145)
				{
					if(lst->content[i] == TRUE)
					{
						printf("\nadr %p-%p: pppp", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
					}
					i++;
				}
				lst = lst->next;
			}
				printf("\nadresse %p-%p: %zu %lu", lst->content, lst->content + lst->content_size, lst->content_size, sizeof(t_list));
				i = 0;
				while(i < 145)
				{
					if(lst->content[i] == TRUE)
							{
							printf("\nadr %p-%p: ", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
							}
							i++;
							}

		}
		else
		{
		//	printf("HAHAHAHA");
			printf("\nadresse %p-%p: %zu", lst->content, lst->content + lst->content_size, lst->content_size);
			i = 0;
			while(i < 145)
			{

				if(lst->content[i] == TRUE)
				{
//					printf("malborolight, %d,***** %c ooooo %p", i, lst->content[i], lst);
					printf("\nadr %p-%p:", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
				}
				i++;
			}
		}
		/*			while(i < 145)
					{
					if(lst->content == TRUE)
					{
					printf("\nadr %p-%p:", &lst->content[i], lst->content[i+1]);
					}
					i++;
					}*/
	}
}


void	show_alloc_mem(void)
{
	printf("\ntiny");
	browse_lst2(zone.tiny);
	printf("\nsmall");
	browse_lst2(zone.small);
	printf("\nlarge");
	browse_lst2(zone.large);
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
//	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);
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

void		*tiny(size_t size)
{
	if (zone.tiny)
		return (already_tiny(size));
	else
		return (first_tiny(size));
}

void		*ft_malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	else if (size < 65)
		return (tiny(size));
	else if (size < 1025)
		return (small(size));
	else
		return (large(size));
}
