# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 21:39:45 by tbhuiyan          #+#    #+#              #
#    Updated: 2025/05/25 15:51:49 by tbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -MMD

SRCS = ft_convert.c \
	ft_convert2.c \
	ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

INC = ft_printf.h

all : ${NAME}

%.o : %.c ${INC}
	@cc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${INC}
	@ar rc ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: re all clean fclean

-include $(OBJS:.o=.d)