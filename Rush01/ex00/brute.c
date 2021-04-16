/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:29:40 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 02:18:44 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_track_sum(int l, int c);

extern int g_matrix[6][6];

void ft_fill_ns(int n)
{
	int l;
	int c;
	int counter;
	int n_pos_c[5] = {0, 0, 0, 0, 0};
	int n_pos_l[5] = {0, 0, 0, 0, 0};

	l = 1;
	counter = 0;
	while (l < 5)
	{
		c = 1;
		while (c < 5)
		{
			if (g_matrix[l][c] == n)
			{
				n_pos_c[c] = n;
				n_pos_l[l] = n;
				counter++;
			}
			c++;
		}
		l++;
	}
	if (counter == 3)
	{
		l = 1;
		while (n_pos_l[l] == n)
			l++;
		c = 1;
		while (n_pos_c[c] == n)
			c++;
		g_matrix[l][c] = n;
	}	
}

void ft_complete_rows()
{
	int n;
	int l;
	int c;
	int track[5] = {0, 0, 0, 0, 0};
	int i;
	
	l = 1;
	while (l < 5)
	{
		c = 1;
		n = 0;
		i = 1;
		while (c < 5)
		{
			if (g_matrix[l][c] != 0)
			{
				track[c] = 1;
				n++;
			}
			else
				track[c] = 0;
			c++;
		}
		if (n == 3)
		{
			while (track[i] != 0)
				i++;
			g_matrix[l][i] = 10 - ft_track_sum(l, 0);
		}
		l++;
	}
}

void ft_complete_cols()
{
	int n;
	int l;
	int c;
	int track[5] = {0, 0, 0, 0, 0};
	int i;
	
	c = 1;
	while (c < 5)
	{
		l = 1;
		n = 0;
		i = 1;
		while (l < 5)
		{
			if (g_matrix[l][c] != 0)
			{
				track[l] = 1;
				n++;
			}
			else
				track[l] = 0;
			l++;
		}
		if (n == 3)
		{
			while (track[i] != 0)
				i++;
			g_matrix[i][c] = 10 - ft_track_sum(0, c);
		}
		c++;
	}
}
