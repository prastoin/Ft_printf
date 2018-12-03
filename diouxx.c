/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:12 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 17:46:55 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_d(char *str, t_args args, va_list ap, int flag)
{
	int					len;
	long long			tmp;
	long long			nbr;
	int					neg;
	unsigned long long	n;

	(void)str;
	len = 0;
	tmp = va_arg(ap, long long);
	if (flag == 0)
		nbr = (int)tmp;
	if (flag == 1)
		nbr = (long int)tmp;
	if (flag == 2)
		nbr = (long long int)tmp;
	if (flag == 3)
		nbr = (short int)tmp;
	if (flag == 4)
		nbr = (short int)tmp;
	neg = nbr < 0 ? 1 : 0;
	n = nbr < 0 ? -nbr : nbr;
	while (ft_power(10, len) <= n)
		len++;
	args.preci = args.preci > len ? args.preci : len;
	if (args.padd != 0 && args.padd > args.preci)
		printpadd(args.padd, args.preci + neg);
	if (neg == 1)
		ft_putchar('-');
	while (args.preci > len)
	{
		ft_putchar('0');
		len++;
	}
	ft_putnnbr(n);
}
