/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:48:49 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 14:02:31 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_count(int nb)
{
	int i;

	i = 0;
	while (i / 10 > 0)
		i++;
	return (i);
}*/

t_args		getarg(const char *fmt, t_args args)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (fmt[i] != 'd' && fmt[i] != 'u' && fmt[i] != 'X' && fmt[i] != 'x' 
			&& fmt[i] != 'i' && fmt[i] != 'c' && fmt[i] != 's' && fmt[i] != 'f'
			&& fmt[i] != 'p' && fmt[i] != 'o')
	{
		args.str[a] = fmt[i];
		i++;
		a++;
	}
	args.str[a] = fmt[i];
	args.flag = fmt[i];
	args.str[a + 1] = '\0';
	return (args);
}
