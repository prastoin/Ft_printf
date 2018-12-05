# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 15:24:29 by ochaar            #+#    #+#              #
#    Updated: 2018/12/05 13:51:10 by prastoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printptr.c ft_printf.c solver.c padding.c display.c diouxx.c \
	   ft_putnnbr.c ft_atoi.c ft_putchar.c ft_power.c ft_putnstr.c \
	   ft_putstr.c ft_strlen.c ft_itoa_hexa.c ft_itoa_hexaxX.c xoxo.c \
	   ft_itoa_octo.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc  $(FLAGS) -c $(SRCS) 
	ar rc $(NAME)  $(OBJ)
clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
