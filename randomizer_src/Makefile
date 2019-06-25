# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/25 17:47:28 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = randomizer

LIBFT = ../libft/libft.a

C_FLAGS = -g

HEADER = -I ../includes

SRC = src/main.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	gcc $(C_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(HEADER)

$(LIBFT):
	make -C ../libft

clean:
	@make -C ../libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ../libft fclean

val:
	valgrind --leak-check=full ./$(NAME)

re: fclean all
