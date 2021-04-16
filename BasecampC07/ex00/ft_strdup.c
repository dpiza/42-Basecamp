/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:13:55 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/14 19:04:17 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	ptr = malloc(size * sizeof(char) + 1);
	while (i <= size)
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}
