# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paminna <paminna@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 22:15:42 by paminna           #+#    #+#              #
#    Updated: 2021/01/11 22:19:15 by paminna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_parser.c ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

NAME = 

AR = ar rc

RUN = ranlib

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

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