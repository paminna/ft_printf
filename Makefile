# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paminna <paminna@stud.21-school.ru>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 22:15:42 by paminna           #+#    #+#              #
#    Updated: 2021/01/27 22:32:23 by paminna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_parser.c ft_printf.c ft_printf_utils.c ft_char.c ft_numbers.c ft_process.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

AR = ar rc

RUN = ranlib

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
			 	${CC} ${CFLAGS} -c $< 

$(NAME):		${OBJS}
				${AR} ${NAME} ${OBJS}
				${RUN} ${NAME} 

all: ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: all clean fclean re bonus