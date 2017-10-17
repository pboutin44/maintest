/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:37:51 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/17 22:40:08 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"malloc.h"

int		main(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

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


///   fonction d'affichage
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	get_hexnum_size(unsigned char *hex_size, unsigned char dec_byte)
{
	while (dec_byte > 0)
	{
		(*hex_size)++;
		dec_byte /= 16;
	}
}

void	ft_putaddr_byte(unsigned char dec_byte)
{
	unsigned char			hex_size;
	unsigned char			hex_num[3];

	hex_size = 0;
	get_hexnum_size(&hex_size, dec_byte);
	if (hex_size == 0)
		ft_putstr("00");
	else if (hex_size == 1)
		ft_putchar('0');
	hex_num[hex_size] = '\0';
	while (dec_byte > 0)
	{
		if ((dec_byte % 16) < 10)
			hex_num[hex_size - 1] = (unsigned char)((dec_byte % 16) + 48);
		else
			hex_num[hex_size - 1] = (unsigned char)((dec_byte % 16) + 87);
		hex_size--;
		dec_byte /= 16;
	}
	ft_putstr((const char*)hex_num);
}

void	ft_putaddr(const void *addr)
{
	unsigned char			dec_byte;
	int						hex_addr_len;

	if (addr == NULL)
	{
		ft_putstr("(nil)");
		return ;
	}
	dec_byte = 0;
	hex_addr_len = 4;
	ft_putstr("0x");
	while (hex_addr_len >= 0)
	{
		dec_byte = ((unsigned char*)&addr)[hex_addr_len];
		ft_putaddr_byte(dec_byte);
		hex_addr_len--;
	}
}

//||||| display function

void		browse_lst2(t_list *lst)
{
	int		i;

	if (lst)
	{
		while (lst->next)
		{
			printf("\nadresse %p-%p: %zu", lst->content, lst->content + lst->content_size, lst->content_size);
			ft_putstr("ibouvi1\n");
			ft_putaddr(lst->content);
			ft_putstr("\nibouvi2\n");
			i = 25;
			while(i < 145)
			{
				if(lst->content[i] == TRUE)
					printf("\nadr %p-%p: 64", &lst->content[(i - 25) * 64 + 192], &lst->content[((i + 1) - 25 ) * 64 +192]);
				i++;
			}
			lst = lst->next;
		}
		printf("\nadresse %p-%p: %zu", lst->content, lst->content + lst->content_size, lst->content_size);
		i = 25;
		while(i < 145)
		{
			if(lst->content[i] == TRUE)
				printf("\nadr %p-%p: 64", &lst->content[(i - 25) * 64 + 192], &lst->content[((i + 1) - 25 ) * 64 + 192]);
			i++;
		}
	}
}

void		show_alloc_mem(void)
{
	printf("\nTiny_zone");
	browse_lst2(g_zone.tiny);
	printf("\nsmall_zone");
	browse_lst2(g_zone.small);
	printf("\nlarge_zone");
	browse_lst2(g_zone.large);
}

t_list		*ft_lstiter(t_list *lst, int (f)(t_list *elem))
{
	t_list	*tmp;

	if (lst && f)
	{
		tmp = lst;
		while (tmp)
		{
			if (f(tmp) == 1)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
	}
	return (NULL);
}

void		*large(size_t size)
{
	void *ret;

	if (g_zone.large)
	{
		ret = already_large(size);
		return (ret);
	}
	else
	{
		ret = first_large(size);
		return (ret);
	}
}

void		*small(size_t size)
{
	void *ret;

	if (g_zone.small)
	{
		ret = already_small(size);
		return (ret);
	}
	else
	{
		ret = first_small(size);
		return (ret);
	}
}

void		*tiny(size_t size)
{
	void *ret;

	if (g_zone.tiny)
	{
		ret = already_tiny(size);
		return (ret);
	}
	else
	{
		ret = first_tiny(size);
		return (ret);
	}
}

void		*malloc(size_t size)
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
