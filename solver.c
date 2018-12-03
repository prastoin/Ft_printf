/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:34:28 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 15:23:26 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args		common(char *str, t_args args)
{
	int		i;
	char	count[10];
	int		j;
	int		preci;
	int		less;

	less = 0;
	preci = 0;
	j = 0;
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
			preci = 1;
		if (str[i] == '-')
			less = 1;
		if (str[i] > '0' && str[i] <= '9')
		{
			count[j] = str[i];
			i++;
			j++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				count[j] = str[i];
				i++;
				j++;
			}
			i--;
			count[j] = '\0';
			if (preci == 0 && less == 0)
			{
				args.padd = ft_atoi(count);
				printf("%d\n", args.padd);
				j = 0;
			}
			if (preci != 0 && less == 0)
			{
				args.preci = ft_atoi(count);
				preci = 0;
				j = 0;
			}
			if (preci == 0 && less != 0)
			{
				args.less = ft_atoi(count);
				less = 0;
				j = 0;
			}
		}
		i++;
	}
	return (args);
}

int		csp(char *str, t_args args, va_list ap)
{
	int		i;
	int		len;
	int		j;
	char	*tmp;
	char	c;

	c = 0;
	tmp = NULL;
	(void)str;
	j = 0;
	i = 0;
	if (args.flag == 'c')
	{
		len = 1;
		c =  va_arg(ap,int);
		if (args.padd != 0 && args.padd > len)
			printpadd(args.padd, len);
		ft_putchar((char)va_arg(ap, int));
		if (args.less != 0)
			printless(args.less, len);
	}
/*	if (args.flag == 'p')
	{
		if (args.padd != 0 && args.padd > len)
			printpadd(args.padd, len);
		tmp = (va_arg(ap, char*));
		ft_putstr(&tmp);
		if ()
	}*/
	if (args.flag == 's')
	{
		tmp = va_arg(ap, char*);
		len = ft_strlen(tmp);
		if (args.preci <= len && args.preci != 0)
			len = args.preci;
		if (args.padd != 0 && args.padd > len)
		 	printpadd(args.padd, len);
		ft_putnstr(tmp, len);
		if (args.less != 0)
			printless(args.less, len);
	}
	return (1);
}
/*
int		diouxx(char *str, t_args args, va_list ap)
{
	int		i;

	i = 0;
	while (str[i])
	{
	}

}

int		flotte(char *str, t_args args, va_list ap)
{
	int		i;

	i = 0;
	while (str[i])
	{

	}

}*/
