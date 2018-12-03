/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:33:08 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 15:08:00 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
