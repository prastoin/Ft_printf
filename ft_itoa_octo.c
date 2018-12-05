/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:43:33 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 16:22:25 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_convbase(char *str, long i, unsigned long nbr)
{
	unsigned long a;
	unsigned long tmp;

	a = 0;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = 0;
		while (nbr >= ft_power(8, i))
		{
			tmp++;
			nbr = nbr - ft_power(8, i);
		}
		str[a] = tmp + '0';
		a++;
		i--;
	}
}

char	*ft_itoa_octo(unsigned long long nbr)
{
	char				*str;
	long long			i;
	unsigned long long	a;

	a = nbr;
	i = 0;
	while (a / 8 > 0)
	{
		i++;
		a = a / 8;
	}
	i += nbr == 0 ? 1 : 0;
	if (!((str = (char *)malloc(sizeof(char) * i + 1))))
		return (NULL);
	i -= nbr == 0 ? 1 : 0;
	ft_convbase(str, i, nbr);
	return (str);
}
