/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:50:23 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 02:15:09 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_matrix[6][6];

void ft_three_one_patterns(int l)
{
	int poties[4][5] = {
		{0,0,0,0,0},
		{0,1,3,2,4},
		{0,2,1,3,4},
		{0,2,3,1,4},
	};
	int i;
	int j;

	i = 1;
	while (g_matrix[l][i] != 1)
		i++;
	if (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			g_matrix[l][j] = poties[i][j];
			j++;
		}
	}
}

void ft_one_three_patterns(int l)
{
	int poties[4][5] = {
		{0,0,0,0,0},
		{0,4,1,3,2},
		{0,4,3,1,2},
		{0,4,2,3,1},
	};
	int i;
	int j;

	i = 2;
	while (g_matrix[l][i] != 1)
		i++;
	if (i < 5)
	{
		j = 2;
		while (j < 5)
		{
			g_matrix[l][j] = poties[i][j];
			j++;
		}
	}
}

void ft_two_one_patterns(int l)
{
	int poties[3][5] = {
		{0,0,0,0,0},
		{0,3,1,2,4},
		{0,3,2,1,4},
	};
	int i;
	int j;

	i = 1;
	while (g_matrix[l][i] != 1)
		i++;
	if (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			g_matrix[l][j] = poties[i][j];
			j++;
		}
	}
}

void ft_one_two_patterns(int l)
{
	int poties[3][5] = {
		{0,0,0,0,0},
		{0,4,1,2,3},
		{0,4,2,1,3},
	};
	int i;
	int j;

	i = 2;
	while (g_matrix[l][i] != 1)
		i++;
	if (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			g_matrix[l][j] = poties[i-1][j];
			j++;
		}
	}
}

void ft_apply_pattern(int l)
{
	int rl;
	int rr;

	rl = g_matrix[l][0];
	rr = g_matrix[l][5];

	if (rl == 3 && rr == 1)
		ft_three_one_patterns(l);
	else if (rl == 1 && rr == 3)
		ft_one_three_patterns(l);
	else if (rl == 2 && rr == 1)
		ft_two_one_patterns(l);
	else if (rl == 1 && rr == 2)
		ft_one_two_patterns(l);
}
