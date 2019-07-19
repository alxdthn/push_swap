# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/07/19 20:13:17 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker

COM_LIB = common.a
PS_LIB = push_swap.a
CH_LIB = checker.a

LIBFT = libft/libft.a
FTPRINTF = libft/ft_printf/libftprintf.a
MLX_LIB = -L /usr/local/lib/ -lmlx
MLX_HEAD = -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit

C_FLAGS = -Wall -Werror -Wextra
HEADER = -I includes -I libft/includes -I libft/ft_printf/includes

SRC_DIR = src/
OBJ_DIR = obj/
PS_DIR = push_swap/
CH_DIR = checker/
COM_DIR = common/

PS_SRC =	push_swap.c \
			push_swap_clear_exit.c \
			insert_method.c \
			pull_b.c \
			handle_mode.c \
			stack_operations.c \
			print.c
CH_SRC =	checker.c \
			checker_clear_exit.c \
			visualisation.c \
			key_handle.c \
			render.c
COM_SRC =	init.c \
			process_commands.c \
			is_sorted.c \
			push.c \
			swap.c \
			rotate.c \
			check_matches.c \
			mark_operations.c \
			get_info.c \
			get_cmd.c

COM_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(COM_SRC)))
PS_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PS_SRC)))
CH_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CH_SRC)))

all: $(PS) $(CH)

$(PS): $(LIBFT) $(FTPRINTF) $(COM_LIB) $(PS_LIB)
	gcc $(C_FLAGS) -o $@ $(COM_LIB) $(LIBFT) $(FTPRINTF) $(PS_LIB) $(HEADER)
$(CH): $(LIBFT) $(FTPRINTF) $(COM_LIB) $(CH_LIB)
	gcc $(C_FLAGS) -o $@ $(COM_LIB) $(LIBFT) $(FTPRINTF) $(CH_LIB) $(HEADER) $(MLX_HEAD) $(FRAMEWORK) $(MLX_LIB)

$(LIBFT):
	make -C libft/
$(FTPRINTF):
	make -C libft/ft_printf/

$(COM_LIB): $(COM_OBJ) 
	@ar rc $@ $^
$(PS_LIB): $(PS_OBJ) 
	@ar rc $@ $^
$(CH_LIB): $(CH_OBJ)
	@ar rc $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)$(COM_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)$(PS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)$(CH_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

clean:
	rm -f $(COM_LIB)
	rm -f $(CH_LIB)
	rm -f $(PS_LIB)
	rm -rf $(OBJ_DIR)

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
