# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 10:52:43 by lmkhwana          #+#    #+#              #
#    Updated: 2018/06/14 12:54:54 by lmkhwana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
HEADER = libft.h
OBJ = *.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES) -I $(HEADER)
	ar rc libft.a $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY: clean fclean
