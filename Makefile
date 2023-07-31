# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeaufil <nbeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 15:08:19 by nbeaufil          #+#    #+#              #
#    Updated: 2023/07/31 08:46:05 by nbeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	p_alloc/p_alloc.c		\
			p_alloc/p_alloc_lst.c

CC		=	gcc
OBJS	=	${SRCS:.c=.o}
NAME	=	libp_alloc.a
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I p_alloc
DEBUG	=

.c.o	:
	${CC} ${FLAGS} ${INCLUDE} ${DEBUG} -c $< -o ${<:.c=.o}

all	:	${NAME}

$(NAME)	:	${OBJS}
	ar -rcs ${NAME} ${OBJS}
	ranlib ${NAME}

test	:	$(NAME)
	${CC} ${INCLUDE} test.c -c -o test.o
	${CC} test.o -L. -lp_alloc ${INCLUDE} -o test

clean	:
	rm -f ${OBJS}
	rm -f test.o

fclean	:	clean
	rm -f ${NAME}
	rm -f test

re	:	fclean all

.PHONY: all clean fclean re

.SILENT:
