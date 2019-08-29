/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:31:58 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 15:39:30 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	t_fdf_env *env;

	if (!(env = (t_fdf_env *)ft_memalloc(sizeof(t_fdf_env))))
		ft_error("Malloc error for t_fdf_env in create_env");
	ft_putendl(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_fdf_env *env;

	if (!(env = (t_fdf_env *)ft_memalloc(sizeof(t_fdf_env))))
		ft_error("Malloc error for t_fdf_env in create_env");
	if (argc != 2)
		ft_error("Usage: ./fdf <file>\n");
	FILENAME = argv[1];
	fdf_valid(argv[1]);
	create_env(&*env);
	return (0);
}
