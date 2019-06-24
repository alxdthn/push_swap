# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 15:02:28 by nalexand          #+#    #+#              #
#    Updated: 2019/06/13 15:26:22 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CС = gcc -Wall -Werror -Wextra -g -c

SRC_DIR = src/

OBJ_DIR = obj/

SRC =	ft_arraydel.c \
		ft_atoi.c \
		ft_btoa.c \
		ft_bzero.c \
		ft_emalloc.c \
		ft_intlen.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstclear.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memdup.c \
		ft_memjoin.c \
		ft_memmove.c \
		ft_memrev.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_read_to_str.c \
		ft_reverse_bits.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclen.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strcskp.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strsskp.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swap.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_wrdcount.c \
		ft_atoi_base.c \
		ft_power.c \
		ft_check_file_format.c \
		get_next_line.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = -I includes

C_PATH = $(addprefix $(SRC_DIR), $(SRC))

O_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	@ar -rc $(NAME) $(O_PATH)
	@make -C ./ft_printf
	@mv ./ft_printf/libftprintf.a libft.a
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -g -c $< -o $@ $(HEADER)

clean:
	@rm -f $(O_PATH)
	@rm -rf $(OBJ_DIR)
	@make -C ft_printf clean

fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all
