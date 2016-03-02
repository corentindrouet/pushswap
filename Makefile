# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 10:18:29 by cdrouet           #+#    #+#              #
#    Updated: 2016/03/02 11:55:13 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
	  operation_a.c \
	  operation_b.c \
	  option.c \
	  croissant.c \
	  operation_double.c \
	  tri_rapide.c \

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = -Llibft/ -lftprintf

$(NAME) :
	gcc $(FLAG) -c $(SRC);
	gcc $(FLAG) -o $(NAME) $(BIN) $(LIB)

all : $(NAME)

clean :
	rm -f $(BIN)

fclean : clean
	rm -f $(NAME)

re : fclean all
