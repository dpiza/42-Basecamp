/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:50:38 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 03:03:40 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_fours_to_ones();
void ft_all_to_fours();
void ft_three_to_two_ones();
void ft_four_to_three_twos();
void ft_fill_ns(int n); // checa a ocorrencia de um numer, se houverem 3 dele, aloca o ultimo na posição correta
void ft_complete_rows(); // procura por linhas com 3 elementos e preenche o ultimo
void ft_complete_cols(); // procura por colunas com 3 elementos e preenche o ultimo
void ft_apply_pattern(int l); // aplica alguma regra de padrao baseada nos tips da linha
int ft_track_sum(int l, int c); // Retorna soma dos caracteres da linha/coluna (10 = linha completa)
int ft_check_tip_status(int l); // Checa se ambas regras estão sendo respeitadas. 0 - N ; 10 - rl ; 1 - rr ; 11 - ambas

void ft_solve()
{
	int p;
	int i;
	int j;

	p = 0;
	i = 0;
	ft_fours_to_ones();	
	ft_all_to_fours();
	ft_three_to_two_ones();
	ft_four_to_three_twos();

	while (i < 10)
	{
		ft_fill_ns(1);
		ft_fill_ns(2);
		ft_fill_ns(3);
		ft_fill_ns(4);

		ft_complete_rows();
		ft_complete_cols();
		j = 1;
		while(j < 5)
		{
			p = ft_track_sum(j, 0);
			if (p != 10)
			{
				ft_apply_pattern(j);
			}
			if (j == 4 && p == 10)
				return;
			j++;
		}
		i++;
	}
}