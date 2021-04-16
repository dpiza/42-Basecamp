/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:44:21 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/03 22:54:15 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_numbers(char i, char j, char k, char l)
{
	if ((k > i) || (k >= i && l > j))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, " ", 1);
		write(1, &k, 1);
		write(1, &l, 1);
		if (!(i == '9' && j == '8' && k == '9' && l == '9'))
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;
	int k;
	int l;

	i = '0' - 1;
	while (i++ < '9')
	{
		j = '0' - 1;
		while (j++ < '9')
		{
			k = '0' - 1;
			while (k++ < '9')
			{
				l = '0' - 1;
				while (l++ < '9')
				{
					ft_write_numbers(i, j, k, l);
				}
			}
		}
	}
}
