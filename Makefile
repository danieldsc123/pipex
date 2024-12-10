# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 23:00:00 by danielda          #+#    #+#              #
#    Updated: 2024/12/08 18:09:27 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = pipex.c utils.c # Adicione todos os arquivos .c aqui
OBJ = $(SRC:.c=.o)
LIBFT_A = $(LIBFT)/libft.a
#MAIN = pipex.c utils.c
HEADER = -I includes

# Directories
INCLUDE_DIR = includes

# Rules

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_A)

$(LIBFT_A):
	make -C $(LIBFT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $^

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
