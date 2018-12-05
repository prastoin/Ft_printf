/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:12 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 18:11:58 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long ft_dcut(long long nbr, int flag, va_list ap)
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
		nbr = (short)tmp;
	if (flag == 4)
		nbr = (char)tmp;
	return (nbr);
}

int		checkplus(char *str)
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

int		checksp(char *str)
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

int		checkpreci(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		check0(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	i = 0;
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

void		ft_d(char *str, t_args *args, va_list ap, int flag)
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
	if (nbr == 0 && args->preci == 0 && args->padd == 0 && args->less == 0 && checkpreci(str) == 1)
		return ;
	if (nbr == 0)
		len++;
	while (ft_power(10, len) <= n)
		len++;
	checksp(str) == 1  && neg == 0 && checkplus(str) != 1 ? ft_putchar(' ', args) : 0;
	curr = args->preci > len ? args->preci : len;
	if (args->padd != 0 && args->padd > curr && check0(str) == 0)
		printpadd0(args->padd, curr + neg + (checkplus(str) == 1 || checksp(str) == 1 ? 1 : 0), ' ', args);
	checkplus(str) == 1  && neg == 0 ? ft_putchar('+', args) : 0;
	if (neg == 1)
		ft_putchar('-', args);
	if (args->padd != 0 && args->padd > curr && check0(str) == 1)
		printpadd0(args->padd, curr + neg + (checkplus(str) == 1 || checksp(str) == 1 ? 1 : 0), '0', args);
	while (args->preci > len)
	{
		ft_putchar('0', args);
		len++;
	}
	ft_putnnbr(n, args);
	if (args->less != 0)
		printless(args->less, len, args);
}

static long long unsigned	ft_ucut(long long unsigned nbr, int flag, va_list ap)
{
	long long unsigned			tmp;

	tmp = va_arg(ap, unsigned long long);
	if (flag == 0)
		nbr = (unsigned int)tmp;
	if (flag == 1)
		nbr = (unsigned long int)tmp;
	if (flag == 2)
		nbr = (unsigned long long int)tmp;
	if (flag == 3)
		nbr = (unsigned short)tmp;
	if (flag == 4)
		nbr = (unsigned char)tmp;
	return (nbr);
}

void		ft_u(char *str, t_args *args, va_list ap, int flag)
{
	int					len;
	unsigned long long			nbr;
	unsigned long long			tmp;

	(void)str;
	len = 0;
	nbr = ft_ucut(0, flag, ap);
	tmp = nbr;
	if (tmp == 0 && args->preci == 0 && args->padd == 0 && args->less == 0 && checkpreci(str) == 1)
		return ;
	if (nbr == 0)
		len++;
	while (tmp > 0)
	{
		tmp = tmp /10;
		len++;
	}
	args->preci = args->preci > len ? args->preci : len;
	if (args->padd != 0 && args->padd > args->preci)
		printpadd(args->padd, args->preci, args);
	while (args->preci > len)
	{
		ft_putchar('0', args);
		len++;
	}
	ft_putnnbr(nbr, args);
	if (args->less != 0)
		printless(args->less, len, args);
}
