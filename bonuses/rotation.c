/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:47:14 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/18 21:14:08 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation(double *x, double *y, double *z, t_cam *view_rot)
{
	t_coord	tmp;

	tmp.x = (*x + *y) * cos(0.0125 * view_rot->x);
	tmp.y = (*x - *y) * sin(0.0125 * view_rot->y) - *z;
	*x = tmp.x;
	*y = tmp.y;
}
