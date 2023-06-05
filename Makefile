# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <rmount@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:20:57 by rmount            #+#    #+#              #
#    Updated: 2023/06/05 13:50:10 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheader_files/ 

SRC = srcs/*.c
PRINTF = ft_printf/
PRINTF_A = $(PRINTF)*.a
BUFF_SIZE = -D BUFFER_SIZE=100

all: $(PRINTF_A)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF_A) $(BUFF_SIZE) $(LIB) -o $(NAME)

$(PRINTF_A):
	make -C $(PRINTF)
	cp -f $(PRINTF)headers/* header_files

clean:
	make clean -C $(PRINTF)
	rm -rf $(NAME)

fclean: clean
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re