# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-conc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/23 14:48:52 by rda-conc          #+#    #+#              #
#    Updated: 2017/08/23 15:41:17 by rda-conc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean

NAME = bsq

SRC = ft_get_params.c ft_str_is_printable.c ft_check_map_empty.c ft_putchar.c \
	  ft_strcatdup.c ft_convert_to_tab.c ft_putnbr.c ft_strdup.c ft_error.c \
	  ft_putstr.c ft_strlen.c ft_get_number.c ft_read.c affichage.c check.c \
	  search.c

SRCO = ft_get_params.o ft_str_is_printable.o ft_check_map_empty.o ft_putchar.o \
	   ft_strcatdup.o ft_convert_to_tab.o ft_putnbr.o ft_strdup.o ft_error.o \
	   ft_putstr.o ft_strlen.o ft_get_number.o ft_read.o affichage.o check.o \
	   search.o


all: compile
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRCO)

compile:
	gcc -c $(SRC)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
