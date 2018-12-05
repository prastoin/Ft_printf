/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:58:38 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 17:53:43 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printptr(void *ptr, int preci, int ispreci)
{
	long long a;
	char *str;

	a = (long long)ptr;
	if (a == 0 && preci == 0 && ispreci == 1)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_itoa_hexa(a);
	return (str);
}
