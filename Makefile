# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/29 04:53:33 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker

LIB = push_swap.a

LIBFT = libft.a
FTPRINTF = libftprintf.a
MLX_LIB = -L /usr/local/lib/ -lmlx
MLX_HEAD = -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit

C_FLAGS = -g
HEADER = -I includes


SRC_DIR = src/
OBJ_DIR = obj/

PS_SRC =	push_swap.c
CH_SRC =	checker.c
SRC =		init.c \
			process_commands.c \
			is_sorted.c \
			push.c \
			swap.c \
			rotate.c \
			clear_exit.c \
			print.c \
			check_matches.c \
			get_info.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))
PS_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PS_SRC)))
CH_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CH_SRC)))

all: $(OBJ_DIR) $(PS) $(CH)

$(PS): $(LIBFT) $(FTPRINTF) $(LIB) $(PS_OBJ)
	gcc $(C_FLAGS) -o $@ $(PS_OBJ) $(LIB) $(LIBFT) $(FTPRINTF) $(HEADER)
$(PS_OBJ): $(SRC_DIR)$(PS_SRC)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

$(CH): $(LIBFT) $(FTPRINTF) $(LIB) $(CH_OBJ) 
	gcc $(C_FLAGS) -o $@ $(CH_OBJ) $(LIB) $(LIBFT) $(FTPRINTF) $(HEADER) $(MLX_HEAD) $(MLX_LIB) $(FRAMEWORK)
$(CH_OBJ): $(SRC_DIR)$(CH_SRC)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

$(LIBFT): libft/$@
	make -C libft/
	cp libft/$@ .

$(FTPRINTF): libft/ft_printf/$@
	make -C libft/ft_printf/
	cp libft/ft_printf/$@ .

$(LIB): $(OBJ)
	ar rc $@ $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIB)
	rm -f $(LIBFT)
	rm -f $(FTPRINTF)

fclean: clean
	rm -f $(PS)
	rm -f $(CH)
	rm -rf *.dSYM

re: fclean all

relib:
	make -C libft/ re

fclean_all: fclean
	make -C libft/ fclean
	make -C libft/ft_printf fclean	
