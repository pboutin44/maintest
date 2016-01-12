/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:08:47 by pboutin           #+#    #+#             */
/*   Updated: 2016/01/12 17:19:46 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawlinebis(t_norm3 norm3, t_env env)
{

	int			y;
	int			x;

	norm3.y2 = roundf(norm3.y2);
	norm3.x2 = roundf(norm3.x2);
	norm3.y1 = roundf(norm3.y1);
	norm3.x1 = roundf(norm3.x1);
	y = roundf(norm3.y1);
	x = roundf(norm3.x1);
	if (norm3.color < norm3.color2)
		norm3.color = norm3.color2 - (2 * 40);
	while ( x != norm3.x2 )
	{
		y = (((norm3.y2 - norm3.y1) / (norm3.x2 - norm3.x1)) * (x - norm3.x1) + norm3.y1);
		mlx_pixel_put(env.mlx, env.win, x, y, norm3.color);
		if (norm3.color < norm3.color2)
			norm3.color = norm3.color + 2;
		if (norm3.color > norm3.color2)
			norm3.color = norm3.color - 2;
		x = (norm3.x1 < norm3.x2) ? x + 1 : x - 1;
/*		if(norm3.x1 < norm3.x2)
			x++;
		else
			x--;*/
	}
	drawlinebisbis(norm3, env, x, y);
}

void	drawlinebisbis(t_norm3 norm3, t_env env, int x, int y)
{
	y = norm3.y1;
	x = norm3.x1;
	if (norm3.color < norm3.color2)
		norm3.color = norm3.color2 - (2 * 40);
	while ( y != norm3.y2 )
	{
		x = (((norm3.x2 - norm3.x1) / (norm3.y2 - norm3.y1)) * (y - norm3.y1) + norm3.x1);
		mlx_pixel_put(env.mlx, env.win, x, y, norm3.color);
		if (norm3.color < norm3.color2)
			norm3.color = norm3.color + 2;
		if (norm3.color > norm3.color2)
			norm3.color = norm3.color - 2;
		if(norm3.y1 < norm3.y2)
			y++;
		else
			y--;
	}
}

t_norm2		key_hook_norm(int keycode, t_env *env, t_norm2 norm2)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		mlx_clear_window(env->mlx, env->win);
		norm2.i++;
		env->coor1 = change_param(env->coor1, norm2.i, 10000, 1);
		drawmap(env->coor1, *env);
	}
	if (keycode == 78)
	{
		mlx_clear_window(env->mlx, env->win);
		norm2.i = 0;
		env->coor1 = change_param(env->coor1, norm2.i, 10000, 0);
		drawmap(env->coor1, *env);
	}
	return (norm2);
}

int		key_hook(int keycode, t_env *env)
{
	static t_norm2	norm2 = {1, 50, 0};

	printf("key:  %d\n", keycode);
	key_hook_norm(keycode, env, norm2);
	if (keycode == 85)
	{
		mlx_clear_window(env->mlx, env->win);
		norm2.y = norm2.y + 1000000;
		env->coor1 = change_param(env->coor1, 0, norm2.y, 1);
		drawmap(env->coor1, *env);
	}
	if (keycode == 92)
	{
		mlx_clear_window(env->mlx, env->win);
		norm2.f = norm2.f + 0.1;
		env->coor1 = change_param(env->coor1, 0, norm2.y, 1);
		env->coor1 = rotationx1(env->coor1, norm2.f);
		drawmap(env->coor1, *env);
	}
	return (0);
}

int		mouse_hook(int boutton,int x, int y, t_env *env)
{
	printf("key:  %d, %d, %d\n", boutton, x, y);
	return (0);
}

int		strlendoublepointeur(char **str)
{
	int		i;

	i = 0;
	while(str[i] != NULL)
		i++;
	return (i);
}

t_coor	**fillcoor2(t_coor **coor, char **str, int y)
{
	int			i;

	i = 0;
	while (str[i] != NULL)
	{
		coor[y][i].x = i;
		coor[y][i].y = y;
		coor[y][i].z = ft_atoi(str[i]);
		i++;
	}
	return (coor);
}

t_coor	**fillcoor1(t_coor **coor, t_coor **coor2, int y, int	strlen)
{
	int			j;
	int			i;
	
	j = 0;
	while (j < y )
	{
		i = 0;
		while (i < strlen)
		{
			coor[j][i].x = coor2[j][i].x;
			coor[j][i].y = coor2[j][i].y;
			coor[j][i].z = coor2[j][i].z;
			i++;
		}
		j++;
	}
	return (coor);
}

t_coor	**allocationcoor(int strlen, int y)
{
	t_coor		**coor;
	int			i;

	i = 0;
	y = y + 1;
	coor = (t_coor **)malloc((y) * sizeof(t_coor*));
	while(i < y)
	{
		coor[i] = (t_coor *)malloc(strlen * sizeof(t_coor));
		i++;
	}
	return (coor);
}


t_coor	**stock(int argc, char **argv)
{
	t_norm1			norm1;

	norm1.y = 0;
	norm1.coor = NULL;
	norm1.buff = NULL;
	norm1.res = 1;
	norm1.fd = open(argv[1], O_RDONLY);
	if (norm1.fd == -1)
	{
		ft_putstr("open() failed\n");
		return (NULL);
	}
	while ((norm1.res = get_next_line(norm1.fd, &norm1.buff)) == 1)
	{
		norm1.str = ft_strsplit(norm1.buff, ' ');
		norm1.strlen = strlendoublepointeur(norm1.str);
		norm1.coor = allocationcoor(norm1.strlen, norm1.y);
		
		norm1.coor = fillcoor1(norm1.coor, norm1.coor2, norm1.y, norm1.strlen);
		norm1.coor = fillcoor2(norm1.coor, norm1.str, norm1.y);
		norm1.y++;
		norm1.coor2 = norm1.coor;
	}
	close(norm1.fd);
	norm1.coor[0][0].nbcolumn = norm1.strlen;
	norm1.coor[0][0].nbline = norm1.y;
	return (norm1.coor);
}

int		main(int argc, char **argv)
{
	t_coor	**coor;
	t_env env;

	if (argc != 2)
		return (1);	
	coor = stock(argc, argv);
	env.mlx = mlx_init ();
	env.win = mlx_new_window (env.mlx, 1900, 1700, "fdf");
	coor = rotationx1(coor, 0);
	coor = change_param(coor, 1, 500000, 1);
	env.coor1 = coor;
	drawmap(coor, env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
