/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:51:41 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/20 11:00:13 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_menu(t_fdf_env *env)
{
	int	c;

	c = WHITE;
	mlx_string_put(MLX, WIN, 16, 5, c,
		"Use Mouse to Rotate the grid, click to start/stop");
	mlx_string_put(MLX, WIN, 18, 25, c, "***Options***");
	mlx_string_put(MLX, WIN, 16, 50, c,
		"Use mouse center button to zoom");
	mlx_string_put(MLX, WIN, 16, 70, c, "use C to switch colors");
	mlx_string_put(MLX, WIN, 16, 90, c, "use R to reset to white");
	mlx_string_put(MLX, WIN, 16, 110, c, "use B to change to bad math");
	mlx_string_put(MLX, WIN, 16, 130, c, "use N to just NO");
	mlx_string_put(MLX, WIN, 16, 150, c, "*****************");
	mlx_string_put(MLX, WIN, 16, 170, c, "use esc to Quit");
}

void	fix_stuff(int **arr, t_fdf_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < MAP->height)
	{
		x = 0;
		while (x < MAP->width)
		{
			arr[y][x++] += -(env->min);
		}
		y++;
	}
}

int		re_render_win(t_fdf_env *env)
{
	mlx_clear_window(MLX, WIN);
	render_grid(&*env);
	fdf_menu(&*env);
	return (0);
}

void	create_env(t_fdf_env *env)
{
	store_here_in_mem(&*env);
	MAP->height = 0;
	MAP->width = 0;
	env->cam->scale_view = 5;
	env->origin.x = WIDTH / 2;
	env->origin.y = HEIGHT / 2;
	env->color = WHITE;
	env->on_off = 0;
	store_coords(&*env);
	fdf_menu(&*env);
	set_up_controls(&*env);
	render_grid(&*env);
	if (WIDTH == 0 && HEIGHT == 0)
		ft_error("Something is very very wrong");
	mlx_loop(MLX);
}
