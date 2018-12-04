/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:58:38 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/04 11:58:39 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printptr(void *ptr)
{
	long long a;
	char *str;

	a = (long long)ptr;
	str = itoa_hexa(a);
	return (str);
}
