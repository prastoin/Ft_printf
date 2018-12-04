/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:12 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/04 14:32:10 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dcut(int nbr, int flag, va_list ap)
{
	long long			tmp;

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
	return (nbr);
}

static int		checkplus(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

static int		checksp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int		check0(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			break;
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

void		ft_d(char *str, t_args args, va_list ap, int flag)
{
	int					len;
	long long			nbr;
	int					neg;
	unsigned long long	n;
	int					curr;

	len = 0;
	nbr = ft_dcut(0, flag, ap);
	neg = nbr < 0 ? 1 : 0;
	n = nbr < 0 ? -nbr : nbr;
	while (ft_power(10, len) <= n)
		len++;
	checkplus(str) == 1  && neg == 0 ? ft_putchar('+') : 0;
	checksp(str) == 1  && neg == 0 && checkplus(str) != 1 ? ft_putchar(' ') : 0;
	curr = args.preci > len ? args.preci : len;
	if (args.padd != 0 && args.padd > curr)
		printpadd0(args.padd, curr + neg + (checkplus(str) == 1 || 
					checksp(str) == 1 ? 1 : 0), (check0(str) == 1 && 
					args.preci == 0 && args.less == 0) ? '0' : ' ');
	if (neg == 1)
		ft_putchar('-');
	while (args.preci > len)
	{
		ft_putchar('0');
		len++;
	}
	ft_putnnbr(n);
	if (args.less != 0)
		printless(args.less, len);
}

static int	ft_ucut(int nbr, int flag, va_list ap)
{
	long long			tmp;

	tmp = va_arg(ap, long long);
	if (flag == 0)
		nbr = (unsigned int)tmp;
	if (flag == 1)
		nbr = (unsigned long int)tmp;
	if (flag == 2)
		nbr = (unsigned long long int)tmp;
	if (flag == 3)
		nbr = (unsigned short int)tmp;
	if (flag == 4)
		nbr = (unsigned short int)tmp;
	return (nbr);
}

void		ft_u(char *str, t_args args, va_list ap, int flag)
{
	int					len;
	unsigned long long			nbr;

	(void)str;
	len = 0;
	nbr = ft_ucut(0, flag, ap);
	while (ft_power(10, len) <= nbr)
		len++;
	args.preci = args.preci > len ? args.preci : len;
	if (args.padd != 0 && args.padd > args.preci)
		printpadd(args.padd, args.preci);
	while (args.preci > len)
	{
		ft_putchar('0');
		len++;
	}
	ft_putnnbr(nbr);
	if (args.less != 0)
		printless(args.less, len);
}
