# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/30 02:57:37 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker

LIB = push_swap.a
CH_LIB = checker.a

LIBFT = libft.a
FTPRINTF = libftprintf.a
MLX_LIB = -L /usr/local/lib/ -lmlx
MLX_HEAD = -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit

C_FLAGS = -g
HEADER = -I includes -I libft/includes -I libft/ft_printf/includes


SRC_DIR = src/
OBJ_DIR = obj/

PS_SRC =	push_swap.c
CH_SRC =	checker.c \
			visualisation.c
SRC =		init.c \
			process_commands.c \
			is_sorted.c \
			push.c \
			swap.c \
			rotate.c \
			clear_exit.c \
			print.c \
			check_matches.c \
			get_info.c \
			get_cmd.c

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))
PS_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PS_SRC)))
CH_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CH_SRC)))

all: $(OBJ_DIR) $(PS) $(CH)

$(PS): $(LIBFT) $(FTPRINTF) $(LIB) $(PS_OBJ)
	gcc $(C_FLAGS) -o $@ $(PS_OBJ) $(LIB) $(LIBFT) $(FTPRINTF) $(HEADER) $(MLX_HEAD) $(FRAMEWORK) $(MLX_LIB)
$(PS_OBJ): $(SRC_DIR)$(PS_SRC)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

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
