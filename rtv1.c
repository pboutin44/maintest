/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:00:08 by pboutin           #+#    #+#             */
/*   Updated: 2016/01/30 21:59:44 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "stdio.h"


int		rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	int		res;

	res = ((a << 24) + (r << 16) + (g << 8) + b);
	return (res);
}

void	fill_image(t_env env, t_coor coor)
{
	unsigned char	*tab;

	if (coor.mode == 0)
		coor.color = rgba(0, 255 / 4, 0, 0);
	if (coor.mode == 1)
		coor.color = rgba((255 / 4) * coor.intensity, (153 / 4) * coor.intensity, (35 / 4) * coor.intensity, 0);
	if (coor.x < WIDTH  && coor.y < LENGHT && coor.x > 0 && coor.y > 0)
	{
		tab = (unsigned char *)env.buff + (int)coor.x * (env.bit_per_pixel / 8) + (int)coor.y * env.size_line;
		tab[0] = ((unsigned char *)(&coor.color))[0];
		tab[1] = ((unsigned char *)(&coor.color))[1];
		tab[2] = ((unsigned char *)(&coor.color))[2];
		tab[3] = ((unsigned char *)(&coor.color))[3];
	}
}

t_param		ray_tracing_cam(t_param param, long double x, long double y)
{
	param.v_rt_x = x;
//	printf("v_rt_x :%Lf\n", param.v_rt_x);
	param.v_rt_y = y;
//	printf("v_rt_y :%Lf\n", param.v_rt_y);
	param.v_rt_z = param.d_l_plan_z;
//	printf("v_rt_z :i%Lf\n", param.v_rt_z);
	return (param);
}

t_param		pre_calcul_sphere(t_param param)
{
//	printf("v_rt :%Lf, %Lf, %Lf\n", param.v_rt_x, param.v_rt_y, param.v_rt_z);
	param.delta_a = param.v_rt_x * param.v_rt_x + param.v_rt_y * param.v_rt_y + param.v_rt_z * param.v_rt_z;
//	printf("%Lf", param.delta_a);
	param.delta_b = - 2 * (param.sphere_x * param.v_rt_x + param.sphere_y * param.v_rt_y + param.sphere_z * param.v_rt_z);
	param.delta_c = (param.sphere_x * param.sphere_x) + (param.sphere_y * param.sphere_y) + (param.sphere_z * param.sphere_z) - (param.sphere_radius * param.sphere_radius);
	param.delta = (param.delta_b * param.delta_b) - (4 * param.delta_a * param.delta_c);
	return (param);
}

/*t_param		pre_calcul_sphere(t_param param)
{
//	printf("v_rt :%Lf, %Lf, %Lf\n", param.v_rt_x, param.v_rt_y, param.v_rt_z);
	param.delta_a = (param.v_rt_z * param.v_rt_z) + (param.v_rt_y * param.v_rt_y) -0.6 * (param.v_rt_x * param.v_rt_x);
//	printf("%Lf", param.delta_a);
	param.delta_b = -100000 * param.v_rt_z -800 * param.v_rt_y + 0.6 * 800 * param.v_rt_x;
	param.delta_c = 50000 * 50000 + 400 * 400 - (400 * 400 * 0.6);
	param.delta = (param.delta_b * param.delta_b) - (4 * param.delta_a * param.delta_c);
	return (param);
}*/

/*
t_param		closer_param(t_param param)
{
	long double first_point;
	long double second_point;

	first_point = ((param.v_rt_x * param.v_rt_x + param.v_rt_y * param.v_rt_y + param.v_rt_z * param.v_rt_z) * ((-param.delta_b - sqrt(param.delta)) / (2 * param.delta_a)));
	second_point = ((param.v_rt_x * param.v_rt_x + param.v_rt_y * param.v_rt_y + param.v_rt_z * param.v_rt_z) * ((-param.delta_b + sqrt(param.delta)) / (2 * param.delta_a)));
	if(first_point < second_point)
		param.closer_param = ((-param.delta_b - sqrt(param.delta)) / (2 * param.delta_a));
	else
		param.closer_param = ((-param.delta_b + sqrt(param.delta)) / (2 * param.delta_a));
	return (param);
}

*/
/*
t_param		ray_tracing_light(t_param param)
{
	param.v_rtl_x = param.v_rt_x * param.closer_param + param.camera_x - param.light_x;
	param.v_rtl_y = param.v_rt_y * param.closer_param + param.camera_y - param.light_y;
	param.v_rtl_z = param.v_rt_z * param.closer_param + param.camera_z - param.light_z;
	return (param);
}

t_param		light_object(t_coor coor, t_param param)
{	
	long double first_point;
	long double second_point;

//	printf("v_rt :%Lf, %Lf, %Lf\n", param.v_rt_x, param.v_rt_y, param.v_rt_z);
	param.delta_l_a = param.v_rtl_x * param.v_rtl_x + param.v_rtl_y * param.v_rtl_y + param.v_rtl_z * param.v_rtl_z;
//	printf("%Lf", param.delta_a);
	param.delta_l_b = 2 * param.v_rtl_x * (param.light_x - param.sphere_x) + 2 * param.v_rtl_y * (param.light_y - param.sphere_y) + 2 * param.v_rtl_z * (param.light_z - param.sphere_z);
	param.delta_l_c = param.sphere_x * param.sphere_x + param.light_x * param.light_x - (2 * param.sphere_x * param.light_x) + param.sphere_y * param.sphere_y + param.light_y * param.light_y - (2 * param.sphere_y * param.light_y) + param.sphere_z * param.sphere_z + param.light_z + param.light_z - (2 * param.sphere_z * param.light_z) - param.sphere_radius * param.sphere_radius;
	param.delta_l = param.delta_l_b * param.delta_l_b - 4 * param.delta_l_a * param.delta_l_c;

	first_point = ((param.v_rtl_x * param.v_rtl_x + param.v_rtl_y * param.v_rtl_y + param.v_rtl_z * param.v_rtl_z) * ((-param.delta_l_b - sqrt(param.delta_l)) / (2 * param.delta_l_a)));
	second_point = ((param.v_rtl_x * param.v_rtl_x + param.v_rtl_y * param.v_rtl_y + param.v_rtl_z * param.v_rtl_z) * ((-param.delta_l_b + sqrt(param.delta_l)) / (2 * param.delta_l_a)));
	if(first_point < second_point)
		param.closer_paraml = ((-param.delta_l_b - sqrt(param.delta_l)) / (2 * param.delta_l_a));
	else
		param.closer_paraml = ((-param.delta_l_b + sqrt(param.delta_l)) / (2 * param.delta_l_a));
	return (param);
}
*/


void	draw_univers(t_env env, t_param param)
{
	long double		x;
	long double		y;
	int		i;
	t_coor	coor;
	
	coor.intensity = 1;
	x = 0;
	y = 0;
	i = 0;
	while(y < LENGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			param = ray_tracing_cam(param, ((x + 0.5) / WIDTH) * 2 - 1, 1 - ((y + 0.5) / LENGHT) * 2);
		//	param.v_rt_x = param.v_rt_x + x;
//	printf("v_rt_x :%Lf\n", param.v_rt_x);
		//	param.v_rt_y = y + param.v_rt_y;
			param = pre_calcul_sphere(param);
//			ft_putnbr(y);
//			ft_putchar('"');
//			ft_putnbr(x);
	/*		if (-40000 / param.v_rt_y <= 0)
			{
//				param = closer_param(param);
//				param = ray_tracing_light(param);
//				param = light_object(coor, param);
//				if(param.delta_l > 0.0000000000005)
//					coor.intensity = 3;
				coor.x = x;
				coor.y = y;
				coor.mode = 0;
				fill_image(env, coor);
			}*/
			if (param.delta > 0)
			{
		//		param = closer_param(param);
		//		printf("#%Lf#\n", param.closer_param);
			/*	param = closer_param(param);
				param = ray_tracing_light(param);
				param = light_object(coor, param);
				if(param.closer_param + param.closer_paraml < 0.0000000000005)
					coor.intensity = 3;*/
//				coor.intensity = 1;
				coor.x = x;
				coor.y = y;
				coor.mode = 1;	
				fill_image(env, coor);
	//			printf("#%d#, #%d#\n", x, y);
//				ft_putnbr(y);
//				ft_putchar('"');
//				ft_putnbr(x);
//				ft_putendl("ok");
			}
			x = x + 1;
		}
		y = y + 1;
	}
	ft_putnbr(i);
}

t_param		init_param(t_param param)
{
	param.light_x = 300;
	param.light_y = 500;
	param.light_z = 200;
	param.camera_x = 0;
	param.camera_y = 0;
	param.camera_z = 0;
	param.d_l_plan_x = 0;
	param.d_l_plan_y = 0;
	param.d_l_plan_z = 1;
	param.sphere_x = 20;
	param.sphere_y = 0;
	param.sphere_z = 30;
	param.sphere_radius = 10;
	return (param);
}

int		main()
{
	t_param param;
	t_env env;

	param = init_param(param);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, LENGHT, "RTV1");
	env.img = mlx_new_image(env.mlx, WIDTH, LENGHT);
	env.buff = mlx_get_data_addr(env.img, &env.bit_per_pixel, &env.size_line, &env.endian);
	draw_univers(env, param);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_loop(env.mlx);

	return (0);
}



