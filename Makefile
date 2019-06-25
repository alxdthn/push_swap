# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/26 02:29:17 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_1 = randomizer
PROG_1_PATH = $(PROG_1)_src/

PROG_2 = push_swap
PROG_2_PATH = $(PROG_2)_src/

all:
	@make -C $(PROG_1_PATH)
	@cp $(PROG_1_PATH)$(PROG_1) .
	@make -C $(PROG_2_PATH)
	@cp $(PROG_2_PATH)$(PROG_2) .

clean:
	@rm -f $(PROG_1)
	@rm -f $(PROG_2)
	@make -C $(PROG_1_PATH) clean
	@make -C $(PROG_2_PATH) clean

fclean: clean
	@make -C $(PROG_1_PATH) fclean
	@make -C $(PROG_2_PATH) fclean

val:
	valgrind --leak-check=full ./$(ARG)

re: fclean all
