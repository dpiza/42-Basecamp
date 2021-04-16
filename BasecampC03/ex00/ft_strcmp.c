/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:16:52 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/08 17:09:55 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int ls1;
	int ls2;
	int i;

	ls1 = 0;
	while (s1[ls1] != '\0')
		ls1++;
	ls2 = 0;
	while (s2[ls2] != '\0')
		ls2++;
	i = 0;
	while (i < ls1 + 1 || i < ls2 + 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
