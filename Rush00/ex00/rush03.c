/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:24:24 by elima-me          #+#    #+#             */
/*   Updated: 2021/04/04 18:33:01 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int l;
	int c;

	l = 1;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((l == 1 && c == 1) || (l == y && c == 1))
				ft_putchar('A');
			else if ((l == 1 && c < x) || (l == y && c < x))
				ft_putchar('B');
			else if ((l == 1 && c == x) || (l == y && c == x))
				ft_putchar('C');
			else if ((l < y && c == 1) || (l < y && c == x))
				ft_putchar('B');
			else if (l < y && c < x)
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
