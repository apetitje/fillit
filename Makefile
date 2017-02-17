# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetitje <apetitje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 17:41:11 by apetitje          #+#    #+#              #
#    Updated: 2016/11/16 15:37:24 by apetitje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = fillit.c input.c backtracking.c ft_putchar.c ft_putstr.c ft_memset.c ft_strdup.c ft_strlen.c ft_strcpy.c parsing.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
