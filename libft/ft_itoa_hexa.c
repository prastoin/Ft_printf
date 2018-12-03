/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:46:19 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 15:48:58 by prastoin         ###   ########.fr       */
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

void	itoa_hexa(unsigned long nbr)
{
	char			str[30];
	unsigned long	i;
	unsigned long	a;

	a = nbr;
	i = 0;
	while (ft_power(16, i) <= a)
		i++;
	i += nbr == 0 ? 1 : 0;
	ft_convbase(str, i, nbr);
	write(1, "0x", 2);
	ft_putstr(str);
}
