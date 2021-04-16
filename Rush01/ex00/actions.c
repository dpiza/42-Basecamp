/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:20:06 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 02:31:29 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int g_matrix[6][6];

void ft_all_to_fours(void)
{
	int k;
	int i;

	k = 0;
	i = 1;
	while(k < 16)
	{
		if (k < 4)
		{
			if (g_matrix[0][i] == 4)
			{
				g_matrix[1][i] = 1;
				g_matrix[2][i] = 2;
				g_matrix[3][i] = 3;
				g_matrix[4][i] = 4;
			}
			i++;
		}
		else if (k >= 4 && k < 8)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[5][i] == 4)
			{
				g_matrix[4][i] = 1;
				g_matrix[3][i] = 2;
				g_matrix[2][i] = 3;
				g_matrix[1][i] = 4;
			}
			i++;
		}
		else if (k >= 8 && k < 12)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[i][0] == 4)
			{
				g_matrix[i][1] = 1;
				g_matrix[i][2] = 2;
				g_matrix[i][3] = 3;
				g_matrix[i][4] = 4;
			}
			i++;
		}
		else if (k >= 8 && k < 16)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[i][5] == 4)
			{
				g_matrix[i][4] = 1;
				g_matrix[i][3] = 2;
				g_matrix[i][2] = 3;
				g_matrix[i][1] = 4;
			}
			i++;
		}
		k++;
	}
}

void ft_fours_to_ones()
{
	int k;
	int i;

	k = 0;
	i = 1;
	while(k < 16)
	{
		if (k < 4)
		{
			if (g_matrix[0][i] == 1)
				g_matrix[1][i] = 4;
			i++;
		}
		else if (k >= 4 && k < 8)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[5][i] == 1)
				g_matrix[4][i] = 4;
			i++;
		}
		else if (k >= 8 && k < 12)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[i][0] == 1)
				g_matrix[i][1] = 4;
			i++;
		}
		else if (k >= 8 && k < 16)
		{
			if (!(i <= 4))
				i = 1;
			if (g_matrix[i][5] == 1)
				g_matrix[i][4] = 4;
			i++;
		}
		k++;
	}	
}

void ft_three_to_two_ones()
{
	int i;
	
	i = 1;
	while (i < 5)
	{
		if (g_matrix[i][0] == 2 && g_matrix[i][5] == 1)
			g_matrix[i][1] = 3;
		else if (g_matrix[i][0] == 1 && g_matrix[i][5] == 2)
			g_matrix[i][4] = 3;
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (g_matrix[0][i] == 2 && g_matrix[5][i] == 1)
			g_matrix[1][i] = 3;
		else if (g_matrix[0][i] == 1 && g_matrix[5][i] == 2)
			g_matrix[4][i] = 3;
		i++;
	}
}

void ft_four_to_three_twos()
{
	int i;
	
	i = 1;
	while (i < 5)
	{
		if (g_matrix[i][0] == 3 && g_matrix[i][5] == 2)
			g_matrix[i][3] = 4;
		else if (g_matrix[i][0] == 2 && g_matrix[i][5] == 3)
			g_matrix[i][2] = 4;
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (g_matrix[0][i] == 3 && g_matrix[5][i] == 2)
			g_matrix[3][i] = 4;
		else if (g_matrix[0][i] == 2 && g_matrix[5][i] == 3)
			g_matrix[2][i] = 4;
		i++;
	}
}

int ft_track_sum(int l, int c)
{
	int sum;
	int i;
	
	i = 1;
	sum = 0;
	if (c == 0)
	{
		while(i < 5)
		{
			sum += g_matrix[l][i];
			i++;
		}
	}
	else if (l == 0)
	{
		while(i < 5)
		{
			sum += g_matrix[i][c];
			i++;
		}
	}
	return (sum);
}

int ft_check_tip_status(int l)
{
	int i;
	int higher;
	int counter;
	int result;

	i = 1;
	counter = 0;
	higher = 0;
	result = 0;
	while (i < 5)
	{
		if (g_matrix[l][i] > higher)
		{
			higher = g_matrix[l][i];
			counter++;
		}
		i++;
	}
	if (g_matrix[l][0] == counter)
		result += 10;
	counter = 0;
	higher = 0;
	i--;
	while (i > 0)
	{
		if (g_matrix[l][i] > higher)
		{
			higher = g_matrix[l][i];
			counter++;
		}
		i--;
	}
	if (g_matrix[l][5] == counter)
		result += 1;
	return (result);
}
