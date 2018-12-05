/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:48:49 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/05 13:37:56 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		verif(char c)
{
	if (c != ' ' && c != '.'  &&c != 'l' && c != 'h' && c != '#' && c != 'L' && c != '-' && c != '+' && !(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

void	getarg(const char *fmt, t_args *args)
{
	int		i;
	int		a;
	char	tmp;

	tmp = '\0';
	a = 0;
	i = 1;
	while (fmt[i] != 'd' && fmt[i] != 'u' && fmt[i] != 'X' && fmt[i] != 'x' 
			&& fmt[i] != 'i' && fmt[i] != 'c' && fmt[i] != 's' && fmt[i] != 'f'
			&& fmt[i] != 'p' && fmt[i] != 'o' && fmt[i])
	{
		if (verif(fmt[i]) != 1)
		{
			tmp = fmt[i];
			break;
		}
		args->str[a] = fmt[i];
		i++;
		a++;
	}
	args->str[a] = fmt[i];
	if (!(tmp))
		args->flag = fmt[i];
	else
		args->flag = tmp;
	args->str[a + 1] = '\0';
}
