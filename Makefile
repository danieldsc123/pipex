# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 18:51:16 by danielda          #+#    #+#              #
#    Updated: 2024/12/04 20:42:58 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= pipex
PROG_B  = pipex_bonus

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= srcs/srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

HEADER	= -Iincludes

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"


bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS_B} -Llibft -lft -o ${PROG_B}
					@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all
