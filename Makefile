# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 23:00:00 by danielda          #+#    #+#              #
#    Updated: 2024/12/05 17:51:26 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c utils.c  # Adicione todos os arquivos .c aqui
OBJ = $(SRC:.c=.o)
LIBFT_A = $(LIBFT)/libft.a
MAIN = pipex.c
HEADER = -Iincludes

# Directories
INCLUDE_DIR = includes

# Rules

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_A)

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
