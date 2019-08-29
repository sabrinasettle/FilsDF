/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_store.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:29:03 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 15:39:01 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		put_stuff(char *str, int *arr, t_fdf_env *env)
{
	int x;
	int i;

	x = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			arr[x++] = ft_atoi(str + i);
			env->min = (arr[x - 1] < env->min) ? arr[x - 1] : env->min;
			while (ft_isdigit(str[i]) || str[i] == '-')
				++i;
		}
	}
}

int			get_size(char *str)
{
	int size;
	int i;

	size = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			++size;
			while (ft_isdigit(str[i]) || str[i] == '-')
				++i;
		}
	}
	return (size);
}

void		find_width_and_height(t_fdf_env *env)
{
	char	*line;
	int		fd;
	int		len;
	int		y;

	y = 0;
	if ((fd = open(FILENAME, O_RDONLY)) < 0)
		ft_error("Error with opening from read_thefile");
	while (get_next_line(fd, &line) == 1)
	{
		len = get_size(line);
		if (!MAP->width)
			MAP->width = len;
		MAP->height++;
		y++;
		free(line);
	}
	close(fd);
}

void		store_coords(t_fdf_env *env)
{
	int		**arr;
	int		fd;
	char	*line;
	int		y;

	find_width_and_height(&*env);
	arr = (int **)ft_memalloc(sizeof(int *) * MAP->height);
	if ((fd = open(FILENAME, O_RDONLY)) < 0)
		ft_error("Error with opening from read_thefile");
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		arr[y] = ft_memalloc(sizeof(int) * MAP->width);
		put_stuff(line, arr[y], &*env);
		y++;
		free(line);
	}
	fix_stuff(&*arr, &*env);
	MAP->arr = *(&arr);
}
