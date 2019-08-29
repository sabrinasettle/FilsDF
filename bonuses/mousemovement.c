/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemovement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:45:36 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/19 15:17:39 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_rel(int button, int x, int y, t_fdf_env *env)
{
	(void)x;
	(void)y;
	(void)button;
	env->mouse->button_pressed = env->mouse->button_pressed ? 0 : 1;
	return (0);
}

void	zoom(char *someting, t_fdf_env *env)
{
	if (someting[0] == 'u')
		CAM->scale_view++;
	else if (someting[0] == 'd')
		CAM->scale_view--;
	if (env->cam->scale_view < 1)
		env->cam->scale_view = 1;
}

int		mouse_scroll(int button, int x, int y, t_fdf_env *env)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_DOWN || button == MOUSE_SCROLL_UP)
	{
		if (button == MOUSE_SCROLL_DOWN)
			zoom("down", &*env);
		if (button == MOUSE_SCROLL_UP)
			zoom("up", &*env);
	}
	re_render_win(&*env);
	return (0);
}

int		mouse_move(int x, int y, t_fdf_env *env)
{
	env->mouse->last_xpos = env->mouse->x_ax;
	env->mouse->last_ypos = env->mouse->y_ax;
	env->mouse->x_ax = x;
	env->mouse->y_ax = y;
	if (MOUSE->button_pressed == 1)
	{
		env->cam->y = env->mouse->y_ax;
		env->cam->x = env->mouse->x_ax;
	}
	re_render_win(&*env);
	return (0);
}
