/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 00:56:08 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/10 02:05:40 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char g_hex_map[16] = "0123456789abcdef";

void	ft_print_hex(unsigned char str)
{
	char hex[2];

	hex[0] = g_hex_map[str / 16];
	hex[1] = g_hex_map[str % 16];
	write(1, hex, 2);
}

void	ft_print_hex_char(char *addr, int begin, int end)
{
	int i;
	int j;
	int null;

	i = 0;
	null = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 2)
		{
			if (null == 0)
				ft_print_hex(addr[begin + i]);
			else
			{
				write(1, "  ", 2);
				null = 1;
			}
			j++;
			i++;
			if (i >= end)
				null = 1;
		}
		write(1, " ", 1);
	}
}

void	ft_print_content(char *addr, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (!(addr[i] >= ' ' && addr[i] <= '~'))
			write(1, ".", 1);
		else
			write(1, (char*)&addr[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*add;
	char			*arr;
	unsigned int	j;
	unsigned int	i;
	unsigned int	k;

	arr = (char*)addr;
	add = (unsigned char*)&addr;
	j = 0;
	while (j < size)
	{
		i = j;
		k = size - j < 16 ? size - j : 16;
		while (i < 8 + j)
		{
			ft_print_hex(add[7 - i + j]);
			i++;
		}
		write(1, ": ", 2);
		ft_print_hex_char(arr, j, k);
		ft_print_content(addr, k);
		j += 16;
		*add += 16;
	}
	return (arr);
}
