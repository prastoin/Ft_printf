/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:47:17 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/05 11:09:20 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnnbr(unsigned long long n, t_args *args)
{
	if (n > 9)
	{
		ft_putnnbr(n / 10, args);
		ft_putnnbr(n % 10, args);
	}
	else
		ft_putchar('0' + n, args);
}
