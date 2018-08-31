# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 09:36:23 by lmkhwana          #+#    #+#              #
#    Updated: 2018/08/31 12:11:33 by lmkhwana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

C_FLAGS = -Wall -Wextra -Werror

LFT_PATH = ./libft/
SRC_PATH = ./src/

INC_NAME = ft_ls.h
SRC_NAME = src/main.c src/get_opts.c src/infos.c \
		   src/print.c src/sort.c src/check.c \
		   src/padding.c src/tools.c

INC = -I ./include -I ./libft/libft.h

all: $(NAME)

$(NAME):
	make -C $(LFT_PATH)
	gcc -o $(NAME) $(SRC_NAME) $(INC) -lft -L$(LFT_PATH)

clean:
	make -C $(LFT_PATH) clean

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
