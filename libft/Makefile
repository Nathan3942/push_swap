# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 16:19:31 by njeanbou          #+#    #+#              #
#    Updated: 2024/02/02 14:00:22 by njeanbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 				= ft_atoi.c ft_bzero.c ft_callloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
						ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
						ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
						ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
						ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS 				= $(SRCS:.c=.o)

SRCSB 				= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
						ft_lstlast_bonus.c \
						ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJSB 				= $(SRCSB:.c=.o)

NAME 				= libft.a
CC 					= gcc
CFLAGS 				= -Wall -Wextra -Werror
LIBC 				= ar rcs
RM 					= rm -f

.c.o: 
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:			${OBJS}
					${LIBC} ${NAME} ${OBJS}

all: 				${NAME}

bonus: 				${NAME} ${OBJSB}
					${LIBC} ${NAME} ${OBJSB}

clean:				
					${RM} ${OBJS} ${OBJSB}

fclean:				clean
					${RM} ${NAME} ${bonus}

re:					fclean all

.PHONY : all bonus clean fclean re

