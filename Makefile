# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnienow <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/25 14:23:03 by mnienow           #+#    #+#              #
#    Updated: 2019/01/25 15:28:42 by mnienow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

FLAGS = -Wall -Wextra -Werror

OUTPUT = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -c ./libft/includes/libft.h
	ar rc $(NAME) $(OUTPUT)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME) ./includes/libft.h.gch

re: fclean all
