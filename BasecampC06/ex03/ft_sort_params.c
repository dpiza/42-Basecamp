/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:16:56 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/13 23:48:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		ls1;
	int		ls2;
	int		i;

	ls1 = 0;
	while (s1[ls1] != '\0')
		ls1++;
	ls2 = 0;
	while (s2[ls2] != '\0')
		ls2++;
	i = 0;
	while (i < ls1 + 1 || i < ls2 + 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_print_result(int argc, char **argv)
{
	int j;
	int i;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
			i++;
		write(1, argv[j], i);
		write(1, "\n", 1);
		j++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*ptemp;

	j = 0;
	while (j < argc)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ptemp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = ptemp;
			}
			i++;
		}
		j++;
	}
	ft_print_result(argc, argv);
	return (0);
}
