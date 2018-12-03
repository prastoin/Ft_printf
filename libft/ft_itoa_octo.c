/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:43:33 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 15:53:23 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_put_octo(long n)
{
	int i;
	long nbr;
	int tmp;

	nbr = 0;
	while (n > 0)
	{
		i = 1;
		tmp = 0;
		while (i <= n)
			i *= 8;
		while (n - i / 8 >= 0)
		{
			tmp++;
			n = n - i / 8;
		}
		nbr = nbr * 10 + tmp;
	}
	ft_putnbr((int)nbr);
}
