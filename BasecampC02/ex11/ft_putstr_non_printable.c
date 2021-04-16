/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:06:01 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/06 20:53:44 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char g_hex_map[16] = "0123456789abcdef";

void	ft_print_hex(unsigned char str)
{
	unsigned char hex[3];

	hex[0] = '\\';
	hex[1] = g_hex_map[str / 16];
	hex[2] = g_hex_map[str % 16];
	write(1, hex, 3);
}

int		ft_char_is_printable(char str)
{
	if (!(str >= ' ' && str <= '~'))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	int				is_printable;

	i = 0;
	while (str[i] != '\0')
	{
		is_printable = ft_char_is_printable(str[i]);
		if (!is_printable)
			ft_print_hex((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
