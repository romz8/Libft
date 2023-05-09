# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 18:02:44 by rjobert           #+#    #+#              #
#    Updated: 2023/05/05 20:38:24 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
SRC = $(wildcard ft_*.c)
OBJS = $(SRC:.c=.o)
HEADER = libft.h
NAME = libft.a

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS)  $< -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -f *.o

re: fclean all

.PHONY: fclean clean re all
