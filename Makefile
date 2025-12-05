# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:12:16 by mbouyer           #+#    #+#              #
#    Updated: 2025/12/05 13:09:18 by mbouyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		 ar rcs ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus
