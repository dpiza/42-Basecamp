/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:46:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/09 01:03:01 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ptf;
	char *found;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str != *to_find)
			str++;
		else
		{
			found = str;
			ptf = to_find;
			while (*str == *ptf && *ptf != '\0' && *str != '\0')
			{
				str++;
				ptf++;
			}
			if (*ptf == '\0')
				return (found);
		}
	}
	return (0);
}
