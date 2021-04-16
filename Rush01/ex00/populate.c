/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:58:41 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 02:22:59 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_matrix[6][6];

void ft_populate(void)
{
	int i = 0;
	int j = 0;
	
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			g_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void ft_print(void)
{
	int i = 0;
	int j = 0;
	char p;

	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			p = g_matrix[i][j] + '0';
			write(1, &p, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void ft_tips(char **ptip)
{
	int k;
	int i;

	k = 0;
	i = 1;
	while(k < 16)
	{
		if (k < 4)
		{
			g_matrix[0][i] = **ptip - '0';
			i++;
		}
		else if (k >= 4 && k < 8)
		{
			if (!(i <= 4))
				i = 1;
			g_matrix[5][i] = **ptip - '0';
			i++;
		}
		else if (k >= 8 && k < 12)
		{
			if (!(i <= 4))
				i = 1;
			g_matrix[i][0] = **ptip - '0';
			i++;
		}
		else if (k >= 8 && k < 16)
		{
			if (!(i <= 4))
				i = 1;
			g_matrix[i][5] = **ptip - '0';
			i++;
		}
		k++;
		*ptip += 2;
	}
}
