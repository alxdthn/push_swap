# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/26 05:30:33 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB = $(NAME).a
LIBFT = ../libft/libft.a
C_FLAGS = -g
HEADER = -I ../includes
SRC_DIR = src/
SRC =	push_swap.c \
		process_commands.c \
		handle_mode.c \
		auto_mode.c \
		push.c \
		swap.c \
		rotate.c \
		clear_exit.c
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

push_swap_prog: $(NAME)

$(NAME): $(LIB)
	@make -C ../libft
	gcc $(C_FLAGS) -o $(NAME) $(LIB) $(LIBFT) $(HEADER)

$(LIB): $(OBJ_DIR) $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -g -c $< -o $@ $(HEADER)

clean:
	rm -rf $(OBJ_DIR)
	@make -C ../libft clean

fclean: clean
	@rm -f $(LIB)
	@rm -rf *.dSYM
	@make -C ../libft fclean

val:
	valgrind --leak-check=full ./$(NAME)

re: fclean push_swap_prog
