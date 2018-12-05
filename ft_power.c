/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:38:22 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 11:26:10 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_power(unsigned long long nbr, unsigned long long pow)
{
	unsigned long long i;
	unsigned long long tmp;

	i = 1;
	tmp = nbr;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		nbr = nbr * tmp;
		i++;
	}
	return (nbr);
}
