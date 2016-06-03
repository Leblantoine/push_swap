# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/01 07:54:43 by aleblanc          #+#    #+#              #
#    Updated: 2016/06/03 10:53:02 by aleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c			\
	  ps_check_stock.c	\
	  ps_return.c		\
	  ps_sort.c			\
	  ps_little_sort.c	\
	  ps_insert_sort.c	\
	  ps_quick_sort.c	\
	  ps_s_sort.c		\
	  ps_p_sort.c		\
	  ps_r_sort.c		\
	  ps_rr_sort.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEAD = push_swap.h

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) -Llibft/ -lft

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
