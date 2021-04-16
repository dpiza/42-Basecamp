/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:22:16 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/11 00:15:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_cat(char str)
{
	if ((str == ' ') || (str <= '\r' && str >= '\t'))
		return (0);
	else if (str == '-' || str == '+')
		return (1);
	else if (str >= '0' && str <= '9')
		return (2);
	return (4);
}

int		ft_atoi(char *str)
{
	int total;
	int minus_counter;

	total = 0;
	minus_counter = 0;
	while ((*str == ' ') || (*str <= '\r' && *str >= '\t'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_counter++;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str != '\0')
	{
		if (total != 0)
			total *= 10;
		total += (int)*str - '0';
		str++;
	}
	if (minus_counter % 2 != 0)
		return (-total);
	return (total);
}
