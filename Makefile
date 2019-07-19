# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/07/19 17:57:35 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker

LIB = common.a
PS_LIB = push_swap.a
CH_LIB = checker.a

LIBFT = libft.a
FTPRINTF = libftprintf.a
MLX_LIB = -L /usr/local/lib/ -lmlx
MLX_HEAD = -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit

C_FLAGS = -g -Wall -Werror -Wextra
HEADER = -I includes -I libft/includes -I libft/ft_printf/includes

SRC_DIR = src/
OBJ_DIR = obj/

PS_SRC =	push_swap.c \
			handle_mode.c \
			insert_method.c \
			pull_b.c \
			stack_operations.c \
			push_swap_clear_exit.c
CH_SRC =	checker.c \
			visualisation.c \
			key_handle.c \
			render.c \
			checker_clear_exit.c
SRC =		init.c \
			process_commands.c \
			is_sorted.c \
			push.c \
			swap.c \
			rotate.c \
			print.c \
			check_matches.c \
			mark_operations.c \
			get_info.c \
			get_cmd.c

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))
PS_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PS_SRC)))
CH_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CH_SRC)))

all: $(OBJ_DIR) $(PS) $(CH)

$(PS): $(LIBFT) $(FTPRINTF) $(LIB) $(PS_LIB)
	gcc $(C_FLAGS) -o $@ $(LIB) $(LIBFT) $(FTPRINTF) $(PS_LIB) $(HEADER)
$(CH): $(LIBFT) $(FTPRINTF) $(LIB) $(CH_LIB) 
	gcc $(C_FLAGS) -o $@ $(LIB) $(LIBFT) $(FTPRINTF) $(CH_LIB) $(HEADER) $(MLX_HEAD) $(FRAMEWORK) $(MLX_LIB)

$(LIBFT): libft/$@
	make -C libft/
	cp libft/$@ .
$(FTPRINTF): libft/ft_printf/$@
	make -C libft/ft_printf/
	cp libft/ft_printf/$@ .

$(LIB): $(OBJ)
	ar rc $@ $(OBJ)
$(PS_LIB): $(PS_OBJ)
	ar rc $@ $(PS_OBJ)
$(CH_LIB): $(CH_OBJ)
	ar rc $@ $(CH_OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)
$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIB)
	rm -f $(CH_LIB)
	rm -f $(PS_LIB)
	rm -f $(LIBFT)
	rm -f $(FTPRINTF)

fclean: clean
	rm -f $(PS)
	rm -f $(CH)
	rm -rf *.dSYM
fclean_all: fclean
	make -C libft/ fclean
	make -C libft/ft_printf fclean

re: fclean all
re_all: re
	make -C libft/ re
	make -C libft/ft_printf re	
relib:
	make -C libft/ re
	make -C libft/ft_printf re
