/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:00:00 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/30 14:23:40 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *fmt, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '\\' && fmt[i + 1] == '\\')
			ft_putchar('\\');
		else if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				ft_putchar('%');
			if (fmt[i] == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (fmt[i] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (fmt[i] == 's')
				ft_putstr(va_arg(ap, char *));
		}
		else
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (1);
}

int main(void)
{
	int		a;

	a = 5;
	ft_printf("on\\ test%% ca %d et %c et %s", a, 'o', "la vie est tellement belle\n");
	printf("on\\ test%% ca %d et %c et %s", a, 'o', "la vie est tellement belle\n");
	return 0;
	return 0;
}
