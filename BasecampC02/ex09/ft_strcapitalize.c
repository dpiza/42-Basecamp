/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:23:44 by dpiza             #+#    #+#             */
/*   Updated: 2021/04/06 18:47:44 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_cat(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	if (str >= 'a' && str <= 'z')
		return (2);
	if (str >= 'A' && str <= 'Z')
		return (3);
	return (0);
}

void	ft_struncapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int should_cap;
	int char_cat;

	i = 0;
	should_cap = 0;
	ft_struncapitalize(str);
	while (str[i] != '\0')
	{
		char_cat = ft_char_cat(str[i]);
		if (i == 0 && char_cat == 2)
			str[i] = str[i] - 'a' + 'A';
		else if (char_cat == 0)
			should_cap = 1;
		else if (char_cat == 1 && should_cap == 1)
			should_cap = 0;
		else if (char_cat == 2 && should_cap == 1)
		{
			str[i] = str[i] - 'a' + 'A';
			should_cap = 0;
		}
		i++;
	}
	return (str);
}
