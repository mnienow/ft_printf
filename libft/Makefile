# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnienow <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:33:43 by mnienow           #+#    #+#              #
#    Updated: 2018/11/30 14:49:24 by mnienow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OUTPUT = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -c ./includes/libft.h
	ar rc $(NAME) $(OUTPUT)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME) ./includes/libft.h.gch

re: fclean all
