/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:10:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/14 23:51:57 by dpiza            ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		ptr_size;
	char	*ptr;

	ptr_size = 0;
	if (size == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr_size += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	ptr = malloc(ptr_size * sizeof(char));
	i = 0;
	while (i < size)
	{
		if (i != 0)
			ptr = ft_strcat(ptr, sep);
		ptr = ft_strcat(ptr, strs[i]);
		i++;
	}
	return (ptr);
}
