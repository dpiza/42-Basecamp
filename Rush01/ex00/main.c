/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:42:46 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/12 02:19:38 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_populate(void);
void ft_tips(char **ptip);
void ft_solve();
void ft_print(void);

int main(int argc, char* argv[])
{
	char **pargv;

	pargv = &argv[1];
	if(argc == 2)
	{
		ft_populate();
		ft_tips(pargv);
		ft_solve();
		ft_print();
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
