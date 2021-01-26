# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/23 14:41:04 by ceccentr          #+#    #+#              #
#    Updated: 2020/11/25 11:02:56 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c help_functions.c parse_arguments.c error.c action.c init.c dead.c end.c sleep.c help_functions2.c

NAME = philo_two

GCC_FLAG = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAG)
LIBS = -pthreads

HEADER = philosophers.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) -c $< -o $@ -g

$(OBJ_RAY): %.o: %.c $(HEADER)
	$(CC) -c $< -o $@ -g

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all