/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:33:08 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 09:00:24 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpadd0(int padd, int len, char c, t_args *args)
{
	int	i;

	i = 0;
	while (i < (padd - len))
	{
		ft_putchar(c, args);
		i++;
	}
}

void	printpadd(int padd, int len, t_args *args)
{
	int	i;

	i = 0;
	while (i < (padd - len))
	{
		ft_putchar(' ', args);
		i++;
	}
}

void	printless(int less, int len, t_args *args)
{
	int	i;

	i = 0;
	while (i < (less - len))
	{
		ft_putchar(' ', args);
		i++;
	}
}
