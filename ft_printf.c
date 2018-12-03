/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:31:25 by fbecerri          #+#    #+#             */
/*   Updated: 2018/12/03 17:43:51 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		ft_print(const char *str, int i)
{
	while (str[i] && str[i] != '%')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i - 1);
}

/*t_args	ft_longtype(const char *c, t_args args)
{
	args.decal = 1;
	args.type[args.args] = 4;

	args.type[args.s] += c[1] == 'u' ? 1 : 0;
	args.decal += c[1] == 'u' ? 1 : 0;

	args.type[args.args] += c[1] == 'l' && c[2] == 'u' ? 2 : 0;
	args.decal += c[1] == 'l' && c[2] == 'u' ? 2 : 0;

	args.type[args.args] += c[1] == 'd' ? 3 : 0;
	args.decal += c[1] == 'd' ? 1 : 0;

	args.type[args.args] += c[1] == 'l' && c[2] == 'd' ? 4 : 0;
	args.decal += c[1] == 'l' && c[2] == 'd' ? 2 : 0;
	return (args);
}

void	ft_impr(va_list ap, t_args args)
{
	if (args.type[args.args] == 1)
		ft_putchar(va_arg(ap, int));
	if (args.type[args.args] == 2)
		ft_putnbr(va_arg(ap, int));
	if (args.type[args.args] == 3)
		ft_putstr(va_arg(ap, char*));
	if (args.type[args.args] == 4)
		ft_putchar('%');
	if (args.type[args.args] == 5)
		ft_putlunbr(va_arg(ap, long unsigned));
	if (args.type[args.args] == 6)
		ft_putllunbr(va_arg(ap, long long unsigned));
	if (args.type[args.args] == 7)
		ft_putldnbr(va_arg(ap, long int));
	if (args.type[args.args] == 8)
		ft_putlldnbr(va_arg(ap, long long int));
}

t_args	ft_type(const char *c, t_args args)
{
	if (c[0] == 'c')
		args.type[args.args] = 1;
	if (c[0] == 'd')
		args.type[args.args] = 2;
	if (c[0] == 's')
		args.type[args.args] = 3;
	if (c[0] == '%')
		args.type[args.args] = 4;
	if (c[0] == 'c' || c[0] == 'd' || c[0] == 's')
		args.decal = 1;
	if (c[0] == 'l')
		args = ft_longtype(c, args);
	return (args);
}*/

int		ft_pass(char *str, t_args args, va_list ap)
{
	args = common(str, args);
//	printf("%d et %d et %c", args.padd, args.less, args.flag);
	if (args.flag == 'd' || args.flag == 'i' || args.flag == 'o' || args.flag == 'u' || args.flag == 'x' || args.flag == 'X')
		diouxx(str, args, ap);
	if (args.flag == 'c' || args.flag == 's' || args.flag == 'p' )
		csp(str, args, ap);
//	if (args.flag == 'f')
//		flotte(str, args, ap);
	return (0);
}

int ft_printf(const char *format, ...)
{
	t_args	args;
	int		i;
	va_list ap;

	i = 0;
	args.args = 0;
	va_start(ap, format);
	while (format[i])
	{
		args.preci = 0;
		args.padd = 0;
		if (format[i] == '%')
		{
			args = getarg(format, args);
			ft_pass(args.str, args, ap);
//			ft_impr(ap, args);
			args.args++;
			i += ft_strlen(args.str) - 1;
		}
		else
			i = ft_print(format, i);
		i++;
	}
	return (0);
}

int main(void)
{
//	printf("%s\n", "ok c'est cool");
	ft_printf("%10.8d\n", -10);
	return 0;
}
