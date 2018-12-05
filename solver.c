/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:34:28 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 18:15:40 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	common(char *str, t_args *args)
{
	int		i;
	char	count[10];
	int		j;
	int		preci;
	int		less;

	less = 0;
	preci = 0;
	j = 0;
	i = 0;
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
				args->padd = ft_atoi(count);
				j = 0;
			}
			if (preci != 0)
			{
				args->preci = ft_atoi(count);
				preci = 0;
				j = 0;
			}
			if (preci == 0 && less != 0)
			{
				args->less = ft_atoi(count);
				less = 0;
				j = 0;
			}
		}
		i++;
	}
}

int		ft_flags(char *str)
{
	int	i;
	int	len;
	int flag;

	flag = 0;
	len = ft_strlen(str) - 1;
	i = 0;
	flag += str[len - 1] == 'l' ? 1 : 0;
	flag += str[len - 2] == 'l' && str[len - 1] == 'l' ? 1 : 0;
	flag += str[len - 1] == 'h' ? 3 : 0;
	flag += str[len - 2] == 'h' && str[len - 1] == 'h' ? 1 : 0;
	return (flag);
}

int		diouxx(char *str, t_args *args, va_list ap)
{
	int i;
	int	flag;

	i = 0;
	flag = ft_flags(str);
	if (args->flag == 'd' || args->flag == 'i')
		ft_d(str, args, ap, flag);
	if (args->flag == 'o')
		ft_o(str, args, ap, flag);
	if (args->flag == 'x' || args->flag == 'X')
		ft_xX(str, args, ap, flag);
	if (args->flag == 'u')
		ft_u(str, args, ap, flag);
	return (0);
}

int		csp(char *str, t_args *args, va_list ap)
{
	int		i;
	int		len;
	int		j;
	char	*tmp;
	char	c;

	c = 0;
	tmp = NULL;
	j = 0;
	i = 0;
	if (args->flag == 'c')
	{
		len = 1;
		c =  va_arg(ap,int);
		if (args->padd != 0 && args->padd > len)
			printpadd0(args->padd, len, (check02(str) == 1 ? '0' : ' '), args);
		ft_putchar((char)c, args);
		if (args->less != 0)
			printless(args->less, len, args);
	}
	if (args->flag == 'p')
	{
		tmp = ft_printptr(va_arg(ap, void *), args->preci, checkpreci(str));
		len = ft_strlen(tmp) + 2;
		if (args->padd != 0 && args->padd > len && check0(str) == 0)
			printpadd(args->padd, len, args);
		ft_putstr("0x", args);
		while (args->preci > len - 2)
		{
		ft_putchar('0', args);
		len++;
		}
		if (check0(str) == 1)
			printpadd0(args->padd, len, '0', args);
		ft_putstr(tmp, args);
		if (args->less != 0)
			printless(args->less, len, args);
		free (tmp);
	}
	if (args->flag == 's')
	{
		tmp = va_arg(ap, char*);
		if (args->preci == 0 && checkpreci(str) == 1)
			tmp = "";
		len = ft_strlen(tmp);
		if (args->preci <= len && args->preci != 0)
			len = args->preci;
		if (args->padd != 0 && args->padd > len)
			printpadd0(args->padd, len,(check02(str) == 1 ? '0' : ' '), args);
		ft_putnstr(tmp, len, args);
		if (args->less != 0)
			printless(args->less, len, args);
	}
	return (1);
}

int		check02(char *str)
{
	int i;

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

int		invalid(char *str, t_args *args)
{
	int	len;

	(void)str;
	len = 1;
	if (args->padd != 0 && args->padd > len)
		printpadd0(args->padd, len,(check02(str) == 1 ? '0' : ' '), args);
	ft_putchar(args->flag, args);
	if (args->less != 0)
		printless(args->less, len, args);
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
