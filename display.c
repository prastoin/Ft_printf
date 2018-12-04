/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:33:08 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/04 14:06:04 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpadd0(int padd, int len, char c)
{
	int	i;

	i = 0;
	while (i < (padd - len))
	{
		ft_putchar(c);
		i++;
	}
}

void	printpadd(int padd, int len)
{
	int	i;

	i = 0;
	while (i < (padd - len))
	{
		ft_putchar(' ');
		i++;
	}
}

void	printless(int less, int len)
{
	int	i;

	i = 0;
	while (i < (less - len))
	{
		ft_putchar(' ');
		i++;
	}
}
