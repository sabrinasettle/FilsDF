/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 00:45:18 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/22 00:50:41 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	buf;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		buf = str[i];
		str[i] = str[len - 1];
		str[len - 1] = buf;
		len--;
		i++;
	}
	return (str);
}
