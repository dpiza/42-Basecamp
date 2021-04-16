/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:42:25 by unazaret          #+#    #+#             */
/*   Updated: 2021/04/04 22:30:16 by elima-me         ###   ########.fr       */
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
			if ((c == 1 && l == 1) || (c == x && l == y))
				ft_putchar('o');
			else if ((c == 1 && l == y) || (l == 1 && c == x))
				ft_putchar('o');
			else if ((l == 1 && c != 1 && c != x) || (l >= 1 && l == y))
				ft_putchar('-');
			else if ((c == 1) || (l == 1) || (l == y) || (c == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
