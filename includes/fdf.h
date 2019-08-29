/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:40:46 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 15:17:22 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include "colors.h"
# include "key_codes.h"
# include "../libft/libft.h"

/*
** WINDOW VALUES
*/

# define TITLE "FDF"
# define WIDTH 1280
# define HEIGHT 720

/*
** MACROS
*/

# define MLX env->mlx_ptr
# define WIN env->win
# define IMG env->img
# define FILENAME env->name_of_file
# define MOUSE env->mouse
# define MAP env->map_vals
# define CAM env->cam

/*
** **************** STRUCTS *******************
*/

typedef struct		s_do_math
{
	double			x;
	double			y;
	double			z;
	double			tmpx;
	double			tmpy;
}					t_do_math;

typedef struct		s_coord
{
	int				y;
	int				x;
}					t_coord;

typedef struct		s_mouse
{
	char			button_pressed;
	int				last_xpos;
	int				last_ypos;
	double			x_ax;
	double			y_ax;
}					t_mouse;

typedef struct		s_map_values
{
	int				height;
	int				z_depth;
	int				z_height;
	int				width;
	int				**arr;
}					t_map_values;

typedef struct		s_cam
{
	double			shiftx;
	double			shifty;
	double			x;
	double			y;
	double			z;
	int				scale_view;
}					t_cam;

typedef struct		s_fdf_env
{
	char			**coord;
	char			*line;
	char			*str;
	char			*name_of_file;
	void			*mlx_ptr;
	void			*win;
	t_coord			origin;
	t_map_values	*map_vals;
	t_cam			*cam;
	t_mouse			*mouse;
	int				color;
	int				i;
	int				j;
	int				on_off;
	int				min;
}					t_fdf_env;

/*
** **************** FUNCTIONS *******************
*/

/*
** ENV
*/

void				create_env(t_fdf_env *env);
void				ft_error(char *str);
void				fdf_valid(char *argv);

/*
** DRAW AND RENDER
*/

void				render_grid(t_fdf_env *env);
int					re_render_win(t_fdf_env *env);

/*
** STORE
*/

void				fix_stuff(int **arr, t_fdf_env *env);
void				store_here_in_mem(t_fdf_env *env);
void				store_coords(t_fdf_env *env);

/*
** CLEANUP
*/

void				del_mem(t_fdf_env *env);

/*
** BONUSS
*/

int					mouse_scroll(int button, int x, int y, t_fdf_env *env);
int					mouse_move(int x, int y, t_fdf_env *env);
int					mouse_rel(int button, int x, int y, t_fdf_env *env);
void				set_up_controls(t_fdf_env *env);
void				rotation(double *x, double *y, double *z, t_cam *view_rot);
int					determine_color(int color);

#endif
