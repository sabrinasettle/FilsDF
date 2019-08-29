/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycontrols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:59:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 18:50:21 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_prog(void)
{
	exit(0);
	return (0);
}

int		key_event(int keycode, t_fdf_env *env)
{
	char	*tmp;

	tmp = ft_itoa(keycode);
	ft_putstr("Key event: ");
	ft_putendl(tmp);
	if (keycode == ESC_KEY)
		close_prog();
	if (keycode == SWITCH_COLOR)
		env->color = determine_color(env->color);
	if (keycode == BAD_FDF)
		env->on_off = env->on_off == 0 ? 1 : 0;
	if (keycode == RESET_COLOR)
		env->color = WHITE;
	re_render_win(&*env);
	if (keycode == NO)
	{
		mlx_clear_window(MLX, WIN);
		mlx_string_put(MLX, WIN, (HEIGHT / 2), (WIDTH / 2), WHITE, "NO");
	}
	free(tmp);
	return (0);
}

void	set_up_controls(t_fdf_env *env)
{
	mlx_hook(WIN, 2, 0, &key_event, &*env);
	mlx_hook(WIN, 4, 0, &mouse_scroll, &*env);
	mlx_hook(WIN, 17, 0, &close_prog, &*env);
	mlx_hook(WIN, 5, 0, &mouse_rel, &*env);
	mlx_hook(WIN, 6, 0, &mouse_move, &*env);
}
