/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:36:40 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 15:17:20 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		draw_point(int x, int y, t_fdf_env *env)
{
	mlx_pixel_put(env->mlx_ptr, env->win, x, y, env->color);
}

static t_coord	do_the_math(t_coord fk, t_fdf_env *env)
{
	t_coord		real;
	t_do_math	b;

	b.tmpx = (double)(CAM->scale_view * WIDTH) / (double)(10 * MAP->width);
	b.tmpy = (double)(CAM->scale_view * HEIGHT) / (double)(10 * MAP->height);
	b.x = b.tmpx + (fk.x * b.tmpx);
	b.y = b.tmpy + (fk.y * b.tmpy);
	b.z = (MAP->arr[fk.y][fk.x] * b.tmpy) / 120.0f + (50.0f * cos(b.x) * 0.0)
		+ (50.0f * cos(b.y) * 0.0) + (env->map_vals->arr[fk.y][fk.x] * 0.7);
	rotation(&b.x, &b.y, &b.z, &*env->cam);
	real.x = ((HEIGHT * 2) / 5) + (b.x * cos(M_PI / 6.0f)) +
		(b.y * cos((M_PI / 6.0f) + 2.0f * (M_PI / 3.0f))) +
		(b.z * (b.z * cos((M_PI / 6.0f) - (2.0f * (M_PI / 3.0f))))) + 0;
	real.y = (WIDTH / 10) + (b.x * sin(M_PI / 6.0f)) +
		(b.y * sin((M_PI / 6.0f) + 2.0f * (M_PI / 3.0f))) +
		(b.z * (b.z * sin((M_PI / 6.0f) - (2.0f * (M_PI / 3.0f))))) +
		(5.0f * (cos((b.z / M_PI)))) + 100;
	return (real);
}

static void		draw_line(t_coord a, t_coord b, t_fdf_env *env)
{
	t_coord max_i;
	t_coord tmp;
	t_coord result;
	t_coord s_a;
	t_coord s_b;

	max_i.x = -1;
	s_a = do_the_math(a, &*env);
	s_b = do_the_math(b, &*env);
	tmp.x = s_a.x - s_b.x > 0 ? s_a.x - s_b.x : -(s_a.x - s_b.x);
	tmp.y = s_a.y - s_b.y > 0 ? s_a.y - s_b.y : -(s_a.y - s_b.y);
	max_i.y = tmp.x < tmp.y ? tmp.y : tmp.x;
	while (++max_i.x < max_i.y)
	{
		result.x = s_a.x + (max_i.x * (s_b.x - s_a.x) / (max_i.y));
		if (env->on_off == 0)
			result.y = s_a.y + (max_i.x * (s_b.y - s_a.y) / (max_i.y));
		else
			result.y = s_a.y + (max_i.x * (s_b.x - s_a.x) / (max_i.y));
		draw_point(result.x, result.y, &*env);
	}
}

static void		connect_a_to_b(int x, int y, t_coord a, t_fdf_env *env)
{
	t_coord b;

	if (x + 1 < env->map_vals->width)
	{
		b.x = x + 1;
		b.y = y;
		draw_line(a, b, &*env);
	}
	if (y - 1 >= 0)
	{
		b.x = x;
		b.y = y - 1;
		draw_line(a, b, &*env);
	}
}

void			render_grid(t_fdf_env *env)
{
	int		x;
	int		y;
	t_coord a;

	y = -1;
	while (++y < env->map_vals->height)
	{
		x = -1;
		while (++x < env->map_vals->width)
		{
			a.x = x;
			a.y = y;
			connect_a_to_b(x, y, a, &*env);
		}
	}
}
