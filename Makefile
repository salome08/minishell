# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shazan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/20 17:08:15 by shazan            #+#    #+#              #
#    Updated: 2015/04/24 16:10:49 by shazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c get_next_line.c str_to_wordtab.c set_env.c env_function.c get_pwd.c
OBJ = $(SRC:.c=.o)
LIB = ./libft/

all: $(NAME)

$(NAME): $(OBJ)
	cd $(LIB) ; make
	$(CC) $(CFLAGS) $(OBJ) $(LIB)libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
