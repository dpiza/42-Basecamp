/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:40:27 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/09 00:58:18 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int l;

	l = 0;
	while (*dest != '\0' && l < size)
	{
		dest++;
		l++;
	}
	while (*src != '\0' && l + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		l++;
	}
	if (l < size)
		*dest = '\0';
	while (*src != '\0')
	{
		src++;
		l++;
	}
	return (l);
}
