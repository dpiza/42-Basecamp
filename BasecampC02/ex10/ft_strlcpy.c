/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:49:09 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/10 02:12:47 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	if (size == 0)
		return (i);
	if (src[i] == '\0')
		return (i);
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i == size && src[i] == '\0')
		dest[i - 1] = '\0';
	else if (i < size)
		dest[i] = '\0';
	else
		dest[i - 1] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
