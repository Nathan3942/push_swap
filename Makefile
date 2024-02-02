# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 14:44:47 by njeanbou          #+#    #+#              #
#    Updated: 2024/02/02 14:00:12 by njeanbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard src/*.c utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re