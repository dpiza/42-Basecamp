/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:40:55 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/16 18:59:00 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	ret = (t_stock_str*)malloc((ac + 1) * sizeof(t_stock_str));
	if (!ret)
		return (0);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = (char*)malloc(ret[i].size + 1);
		if (!ret[i].str)
			return (0);
		ret[i].str = ft_strcpy(ret[i].str, av[i]);
		ret[i].copy = (char*)malloc(ret[i].size + 1);
		if (!ret[i].copy)
			return (0);
		ret[i].copy = ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
