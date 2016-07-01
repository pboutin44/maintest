/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:00:56 by pboutin           #+#    #+#             */
/*   Updated: 2016/01/30 19:40:46 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define WIDTH 800
# define LENGHT 800

typedef struct		s_coor
{
	long double				x;
	long double				y;
	int				color;
	int				intensity;
	int				mode;
}					t_coor;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*buff;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}					t_env;

typedef struct		s_param
{
	long double		camera_x;
	long double		camera_y;
	long double		camera_z;
	long double		d_l_plan_x;
	long double		d_l_plan_y;
	long double		d_l_plan_z;
	long double		sphere_x;
	long double		sphere_y;
	long double		sphere_z;
	long double		sphere_radius;
	long double		v_rt_x;
	long double		v_rt_y;
	long double		v_rt_z;
	long double		delta_a;
	long double		delta_b;
	long double		delta_c;
	long double		delta;
	long double		delta_l_a;
	long double		delta_l_b;
	long double		delta_l_c;
	long double		delta_l;
	long double		closer_param;
	long double		light_x;
	long double		light_y;
	long double		light_z;
	long double		v_rtl_x;
	long double		v_rtl_y;
	long double		v_rtl_z;
	long double		closer_paraml;
}					t_param;


#endif
