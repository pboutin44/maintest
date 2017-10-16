/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:37:51 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/16 23:05:53 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"
/*
int		main(void)
{
	int	i;
	char	*addr;
	void	*str;

	i = 0;
	while(i < 1024)
	{

		addr = (char *)ft_malloc(1024);
		addr[0] = 42;
//		ft_free(addr);
		i++;
	}
	show_alloc_mem();
	return(0);
}
*/


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
				//printf("\nadresse %p-%p: %zu %lu", lst->content, lst->content + lst->content_size, lst->content_size, sizeof(t_list));
				i = 25;
				while(i < 145)
				{
					if(lst->content[i] == TRUE)
					{
						//printf("\nadr %p-%p: pppp", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
					}
					i++;
				}
				lst = lst->next;
			}
				//printf("\nadresse %p-%p: %zu %lu", lst->content, lst->content + lst->content_size, lst->content_size, sizeof(t_list));
				i = 0;
				while(i < 145)
				{
					if(lst->content[i] == TRUE)
							{
							//printf("\nadr %p-%p: ", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
							}
							i++;
							}

		}
		else
		{
		//	//printf("HAHAHAHA");
			//printf("\nadresse %p-%p: %zu", lst->content, lst->content + lst->content_size, lst->content_size);
			i = 0;
			while(i < 145)
			{

				if(lst->content[i] == TRUE)
				{
//					//printf("malborolight, %d,***** %c ooooo %p", i, lst->content[i], lst);
					//printf("\nadr %p-%p:", &lst->content[(i - 25) * 64], &lst->content[((i + 1) - 25 ) * 64]);
				}
				i++;
			}
		}
		/*			while(i < 145)
					{
					if(lst->content == TRUE)
					{
					//printf("\nadr %p-%p:", &lst->content[i], lst->content[i+1]);
					}
					i++;
					}*/
	}
}


void	show_alloc_mem(void)
{
	//printf("\ntiny");
	browse_lst2(zone.tiny);
	//printf("\nsmall");
	browse_lst2(zone.small);
	//printf("\nlarge");
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
//	//printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);
}



void		*large(size_t size)
{
	void *ret;

	if (zone.large){
		ret = already_large(size);
/*		if (ret == NULL)
			ret = (void *)0x44444444;*/
		return (ret);
	}
	else{
		ret = first_large(size);
/*		if (ret == NULL)
			ret = (void *)0x44444444;*/
		return (ret);
	}
}

void		*small(size_t size)
{
	void *ret;
	if (zone.small)
	{
		ret = already_small(size);
/*		if (ret == NULL)
			ret = (void *)0x43434343;*/
		return (ret);
	}
	else{
		ret = first_small(size);
/*		if (ret == NULL)
			ret = (void *)0x43434343;*/
		return (ret);
	}
}

void		*tiny(size_t size)
{
	void *ret;

	if (zone.tiny)
	{
		ret = already_tiny(size);
	/*	if (ret == NULL)
			ret = (void *)0x42424242;*/
		return (ret);
	}
	else{
		ret = first_tiny(size);
/*		if (ret == NULL)
			ret = (void *)0x42424242;*/
		return (ret);
	}
}

void		*malloc(size_t size)
{
	//printf("CACAO");
	//putchar('A');
	if (size <= 0)
		return ((void *)0x42424242);
	else if (size < 65)
		return (tiny(size));
	else if (size < 1025)
		return (small(size));
	else
		return (large(size));
}
