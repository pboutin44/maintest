/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:38:01 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/20 17:22:21 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*buf;
	int		res;

	if (argc == 7)
		fd = 0;
	buf = NULL;
/*	if(argc != 2)
		return (0);*/
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	res = get_next_line(fd, &buf);
//	ft_putnbr(res);
	ft_putendl(buf);
	res = get_next_line(fd, &buf);
	ft_putnbr(res);
	ft_putendl(buf);
	close(fd);
//	res = get_next_line(fd2, &buf);
//	ft_putnbr(res);
//	ft_putendl(buf);
//	res = get_next_line(fd2, &buf);
//	ft_putendl(buf);
//	res = get_next_line(fd2, &buf);
//	ft_putendl(buf);
//	close(fd2);
/*	res = get_next_line(fd, &buf);
	ft_putendl(buf);
	res = get_next_line(fd, &buf);
	ft_putendl(buf);
	res = get_next_line(fd, &buf);
	ft_putendl(buf); */
	return(0);
}
