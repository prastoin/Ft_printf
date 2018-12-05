/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xoxo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:01:57 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 18:07:17 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			checkdiez(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

static long long unsigned	ft_cuto(long long unsigned nbr, int flag, va_list ap)
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

void		ft_o(char *str, t_args *args, va_list ap, int flag)
{
	int							len;
	unsigned long long			nbr;
	char						*s2;

	len = 0;
	nbr = ft_cuto(0, flag, ap);
	if (nbr == 0 && args->preci == 0 && args->padd == 0 && args->less == 0 && checkpreci(str) == 1 && checkdiez(str) == 0)
		return ;
	s2 = ft_itoa_octo(nbr);
	len = ft_strlen(s2);
	args->preci = args->preci > len ? args->preci : len;
	if (args->padd != 0 && args->padd > args->preci)
		printpadd0(args->padd, args->preci + (checkdiez(str) == 1 && nbr != 0 ? 1 : 0),(check0(str) == 1 ? '0' : ' '), args);
	checkdiez(str) == 1 && nbr != 0 ? ft_putstr("0", args) : 0;
	while (args->preci > len + checkdiez(str))
	{
		ft_putchar('0', args);
		len++;
	}
	ft_putstr(s2, args);
	free(s2);
	if (args->less != 0)
		printless(args->less, len + (checkdiez(str) == 1 && nbr != 0 ? 1 : 0), args);
}


static long long unsigned	ft_cutxX(long long unsigned nbr, int flag, va_list ap)
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

void		ft_xX(char *str, t_args *args, va_list ap, int flag)
{
	int							len;
	unsigned long long			nbr;
	char						*s2;


	nbr = ft_cutxX(0, flag, ap);
	if (nbr == 0 && args->preci == 0 && args->padd == 0 && args->less == 0 && checkpreci(str) == 1)
		return;
	s2 = ft_itoa_hexaxX(nbr, args->flag);
	len = ft_strlen(s2);
	args->preci = args->preci > len ? args->preci : len;
	if (args->padd != 0 && args->padd > args->preci)
		printpadd0(args->padd, args->preci + (checkdiez(str) == 1 && nbr != 0 ? 2 : 0), (check0(str) == 1 ? '0' : ' '), args);
	checkdiez(str) == 1 && args->flag == 'X' && nbr != 0 ? ft_putstr("0X", args) : 0;
	checkdiez(str) == 1 && args->flag == 'x' && nbr != 0 ? ft_putstr("0x", args) : 0;
	while (args->preci > len)
	{
		ft_putchar('0', args);
		len++;
	}
	ft_putstr(s2, args);
	free(s2);
	if (args->less != 0)
		printless(args->less, len + (checkdiez(str) == 1 && nbr != 0 ? 2 : 0), args);
}
