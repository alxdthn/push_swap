# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:58:18 by nalexand          #+#    #+#              #
#    Updated: 2019/06/26 02:32:51 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CС = gcc -Wall -Werror -Wextra -g -c

SRC_DIR = src/

OBJ_DIR = obj/

LIB = ../libft.a

SRC =	ft_printf.c \
		pf_ltoa_base.c \
		pf_get_params.c \
		pf_parce.c \
		pf_set_params.c \
		pf_set_zero.c \
		pf_set_task.c \
		pf_set_arg_digit.c \
		pf_solve_digit.c \
		pf_solve_pcsn.c \
		pf_solve_float.c \
		pf_solve_bits.c \
		pf_get_ldbl.c \
		pf_get_float_mod.c \
		pf_get_float_div.c \
		pf_add_lnbr.c \
		pf_multi_lnbr.c \
		pf_lnbr.c \
		pf_unicode.c \
		pf_solve_unicode.c \
		pf_colors.c \
		pf_fun.c \
		pf_debug.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = -I includes

C_PATH = $(addprefix $(SRC_DIR), $(SRC))

O_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	@mv $(LIB) $(NAME)
	@ar -rc $(NAME) $(O_PATH)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -g -c $< -o $@ $(HEADER)

clean:
	@rm -f $(O_PATH)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
