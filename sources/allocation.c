/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:46:54 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 15:39:15 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	store_here_in_mem(t_fdf_env *env)
{
	MLX = mlx_init();
	if (!(WIN = mlx_new_window(MLX, WIDTH, HEIGHT, TITLE)))
		ft_error("WIN has major issue");
	if (!(MAP = (t_map_values *)ft_memalloc(sizeof(t_map_values))))
		ft_error("no mem for MAP struct");
	if (!(CAM = (t_cam *)ft_memalloc(sizeof(t_cam))))
		ft_error("no mem for CAMERA struct");
	if (!(MOUSE = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		ft_error("no mem for MOUSE struct");
}
