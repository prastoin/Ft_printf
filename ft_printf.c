/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:31:25 by fbecerri          #+#    #+#             */
/*   Updated: 2018/12/05 15:40:18 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(const char *str, int i, t_args *args)
{
	while (str[i] && str[i] != '%')
	{
		ft_putchar(str[i], args);
		i++;
	}
	return (i - 1);
}

int		ft_pass(char *str, t_args *args, va_list ap)
{
	common(str, args);
//	printf("padd %d et less %d et preci %d et %c\n", args.padd, args.less, args.preci, args.flag);
	if (args->flag == 'd' || args->flag == 'i' || args->flag == 'o' || args->flag == 'u' || args->flag == 'x' || args->flag == 'X')
		diouxx(str, args, ap);
	else if (args->flag == 'c' || args->flag == 's' || args->flag == 'p' )
		csp(str, args, ap);
//	else if (args.flag == 'f')
//		flotte(str, args, ap);
	else
		invalid(str, args);
	return (0);
}

int ft_printf(const char *format, ...)
{
	t_args	args;
	int		i;
	va_list ap;

	i = 0;
	args.args = 0;
	args.count = 0;
	args.less = 0;
	va_start(ap, format);
	while (format[i])
	{
		args.preci = 0;
		args.padd = 0;
		if (format[i] == '%')
		{
			getarg(format + i, &args);
			if (args.flag == '\0')
				break;
			//			printf("%s\n", args.str);
			ft_pass(args.str, &args, ap);
//			ft_impr(ap, args);
			args.args++;
			i += ft_strlen(args.str);
		}
		else
			i = ft_print(format, i, &args);
		i++;
	}
	return (args.count);
}
