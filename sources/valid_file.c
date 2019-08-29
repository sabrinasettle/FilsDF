/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:31:10 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/21 14:26:12 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** retieves the width of the row for later use
*/

int		get_width(char **coord)
{
	int		i;

	i = 0;
	while (coord[i])
		i++;
	return (i);
}

/*
** Checks the line for any alpha char, '-' minus signs
** and tabs. To which it returns a error if it is
** a char with minus '-a' or '	' tab;
*/

void	check_the_line(char *str)
{
	int		i;

	i = 0;
	if (!*str)
		ft_error("Error this is an invalid file");
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			ft_error("Error this is an invalid file");
		if ((str[i] == '-' && (!(ft_isdigit(str[i + 1])))) || str[i] == '\t')
			ft_error("Error this is an invalid file");
		i++;
	}
}

/*
** Checks the widith validity, so is it even? If uneven returns an error
** and does not run. Does it have any bits of the alphabet in it? If so
** error. It creates the check by calling the get_widith function
** and check_the_line and then freeing the called line from the file
*/

void	line_width(int fd, int width, int wid2, t_fdf_env *env)
{
	char	**tmp2;
	int		i;

	i = 0;
	while ((get_next_line(fd, &(env->line))))
	{
		check_the_line(env->line);
		if ((tmp2 = ft_strsplit(env->line, ' ')) == NULL)
			ft_error("Error with content");
		wid2 = get_width(tmp2);
		if (width != wid2)
			ft_error("Error wrong and uneven width");
		i = wid2;
		while (i >= 0)
			ft_strdel(&tmp2[i--]);
		free(&*tmp2);
		ft_strdel(&env->line);
	}
}

void	width_validity(int fd, int width, int wid2, t_fdf_env *env)
{
	char	**tmp;
	int		i;

	i = 0;
	if (get_next_line(fd, &(env->line)))
	{
		check_the_line(env->line);
		if ((tmp = ft_strsplit(env->line, ' ')) == NULL)
			ft_error("Error with content");
		if (!(width = get_width(tmp)))
			ft_error("Error wrong width");
		i = get_width(tmp);
		ft_strdel(&env->line);
		while (i >= 0)
			ft_strdel(&tmp[i--]);
		free(&*tmp);
	}
	else
		ft_error("Empty file, please try again");
	line_width(fd, width, wid2, &*env);
}

/*
** Checks the validatity of the file for the program to start.
** Does so by going through the argv and checks that input for
** ".fdf" and whether the widith_validity function returns a
** error.
*/

void	fdf_valid(char *argv)
{
	t_fdf_env	*env;
	int			width;
	int			w2;
	int			fd;

	width = 0;
	w2 = 0;
	if (!(env = (t_fdf_env *)ft_memalloc(sizeof(t_fdf_env))))
		ft_error("Malloc error for t_fdf_env in create_env");
	if ((FILENAME = ft_strstr(argv, ".fdf")) == 0)
		ft_error("Error filename is wrong");
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error("Error on opening");
	width_validity(fd, width, w2, &*env);
}
