/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:47:17 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/30 16:00:29 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlldnbr(long long n)
{
	if (n == LLONG_MIN)
		ft_putstr("−9223372036854775808");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putlldnbr(n / 10);
			ft_putlldnbr(n % 10);
		}
		else
			ft_putchar('0' + n);
	}
}
