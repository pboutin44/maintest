/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:38:26 by pboutin           #+#    #+#             */
/*   Updated: 2017/09/27 18:43:54 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# define PSIZE getpagesize()
# define TRUE '1'
# define FALSE '0'


typedef struct      s_list
{
    char            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

typedef struct          s_malloc
{
    t_list              *tiny;
    t_list              *small;
    t_list              *large;
}                       t_malloc;

	t_malloc                zone;

void	*ft_malloc(size_t	size);
void	show_alloc_mem();

#endif

