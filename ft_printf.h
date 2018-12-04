/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:45:36 by fbecerri          #+#    #+#             */
/*   Updated: 2018/12/04 14:11:28 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_struct
{
	int		args;
	char	str[30];
	int		type[2096];
	int		decal;
	char	flag;
	int		padd;
	int		preci;
	int		less;
}				t_args;

/*typedef struct s_darg
{
	int		
}*/

t_args		getarg(const char *fmt, t_args args);

t_args		common(char *str, t_args args);

void	ft_u(char *str, t_args args, va_list ap, int flag);
void	ft_d(char *str, t_args args, va_list ap, int flag);
int		csp(char *str, t_args args, va_list ap);
int		flotte(char *str, t_args args, va_list ap);
int		diouxx(char *str, t_args args, va_list ap);

void	printpadd0(int padd, int len, char c);
char	*ft_printptr(void * ptr);
void	ft_putnnbr(unsigned long long n);
void	printpadd(int padd, int len);
void	printless(int less, int len);

#endif
