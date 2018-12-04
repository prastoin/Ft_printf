/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:46:19 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/04 12:01:45 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convbase(char *str, unsigned long i, unsigned long nbr)
{
	unsigned long a;
	unsigned long tmp;

	a = 0;
	str[i] = '\0';
	while (i > 0)
	{
		tmp = 0;
		while (nbr >= ft_power(16, i - 1))
		{
			tmp++;
			nbr = nbr - ft_power(16, i - 1);
		}
		if (tmp <= 9)
			str[a] = tmp + '0';
		else
			str[a] = tmp - 10 + 'a';
		a++;
		i--;
	}
}

char*	itoa_hexa(unsigned long nbr)
{
	char			*str;
	unsigned long	i;
	unsigned long	a;

	a = nbr;
	i = 0;
	while (ft_power(16, i) <= a)
		i++;
	i += nbr == 0 ? 1 : 0;
	if (!((str = (char *)malloc(sizeof(char) * i + 1))))
			return (NULL);
	ft_convbase(str, i, nbr);
	return (str);
}
