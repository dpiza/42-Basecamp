/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:44:37 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/04 22:30:35 by elima-me         ###   ########.fr       */
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
			if ((c == 1 && l == 1) || (c == x && l == y && l != 1 && c != 1))
				ft_putchar('/');
			else if ((l == 1 && c == x) || (c == 1 && l == y))
				ft_putchar('\\');
			else if ((c == 1) || (l == 1) || (l == y) || (c == x))
				ft_putchar('*');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
