/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:45:36 by fbecerri          #+#    #+#             */
/*   Updated: 2018/12/05 18:14:56 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_struct
{
	int		args;
	char	str[30];
	int		type[2096];
	int		decal;
	char	flag;
	int		padd;
	int		preci;
	int		less;
	int		count;
}					t_args;

/*typedef struct s_darg
{
	int		
}*/

void				getarg(const char *fmt, t_args *args);

void				common(char *str, t_args *args);

void				ft_putstr(const char *str, t_args *args);
void				ft_putnstr(const char *str, int i, t_args *args);
int					ft_putchar(char c, t_args *args);
unsigned long long	ft_power(unsigned long long nbr, unsigned long long pow);
int					ft_atoi(const char *str);
char				*ft_itoa_hexa(unsigned long nbr);
char				*ft_itoa_hexaxX(unsigned long long nbr, char flag);
size_t				ft_strlen(const char *str);
char				*ft_itoa_octo(unsigned long long nbr);

void				ft_u(char *str, t_args *args, va_list ap, int flag);
void				ft_d(char *str, t_args *args, va_list ap, int flag);
void				ft_xX(char *str, t_args *args, va_list ap, int flag);
void				ft_o(char *str, t_args *args, va_list ap, int flag);

int					csp(char *str, t_args *args, va_list ap);
int					flotte(char *str, t_args *args, va_list ap);
int					diouxx(char *str, t_args *args, va_list ap);

int					ft_printf(const char *format, ...);
int					invalid(char *str, t_args *args);

void				printpadd0(int padd, int len, char c, t_args *args);
char				*ft_printptr(void * ptr, int preci, int ispreci);
void				ft_putnnbr(unsigned long long n, t_args *args);
void				printpadd(int padd, int len, t_args *args);
void				printless(int less, int len, t_args *args);

int					checkpreci(char *str);
int					checkplus(char *str);
int					checksp(char *str);
int					check0(char *str);
int					check02(char *str);

#endif
