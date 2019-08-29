/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:04:34 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/18 17:32:32 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	determine_color(int color)
{
	if (color == WHITE)
		color = BLUE;
	else if (color == BLUE)
		color = CYAN;
	else if (color == CYAN)
		color = AQUA_MARINE;
	else if (color == AQUA_MARINE)
		color = GREEN;
	else if (color == GREEN)
		color = LIME;
	else if (color == LIME)
		color = YELLOW;
	else if (color == YELLOW)
		color = ORANGE;
	else if (color == ORANGE)
		color = ORANGE_RED;
	else if (color == ORANGE_RED)
		color = RED;
	else if (color == RED)
		color = HOT_PINK;
	else if (color == HOT_PINK)
		color = DEEP_PINK;
	else if (color == DEEP_PINK)
		color = PURPLE;
	return (color);
}
