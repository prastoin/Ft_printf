/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:27:20 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/05 09:51:54 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnstr(char const *s, int n, t_args *args)
{
	int i;

	i = 0;
	if (!(s))
	{
		ft_putnstr("(null)", n, args);
		return ;
	}
	while (s[i] && i < n)
	{
		ft_putchar(s[i], args);
		i++;
	}
}
