/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:13:54 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/13 20:15:32 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[argc - 1][i] != '\0')
		{
			i++;
		}
		write(1, argv[argc - 1], i);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
