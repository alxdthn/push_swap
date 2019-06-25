# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:28:19 by nalexand          #+#    #+#              #
#    Updated: 2019/06/25 17:37:32 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_1 = randomizer
PROG_1_PATH = randomizer_src/

all: $(PROG_1)

$(PROG_1):
	make -C $(PROG_1_PATH)
	cp $(PROG_1_PATH)$(PROG_1) .

clean:
	rm -f $(PROG_1)
	@make -C $(PROG_1_PATH) clean

fclean: clean
	@make -C $(PROG_1_PATH) fclean

re: fclean all
