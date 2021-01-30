# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 22:15:42 by paminna           #+#    #+#              #
#    Updated: 2021/01/30 20:35:05 by paminna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_parser.c ft_printf.c ft_printf_utils.c ft_char.c ft_numbers.c ft_process_p.c ft_numbers_u.c ft_process_x.c ft_process_bigx.c  ft_numbers_help.c ft_process_p_help.c

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