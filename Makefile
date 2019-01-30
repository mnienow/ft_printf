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

SRCS = ft_printf.c add.c percent.c inta.c 

FLAGS = -Wall -Wextra -Werror

OUTPUT = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) ./libft/ft_itoa.c ./libft/ft_memalloc.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlen.c ./libft/ft_strnew.c -c 
	gcc $(FLAGS) $(SRCS) -c -I ft_printf.h
	ar rc $(NAME) $(OUTPUT)

clean:
	make -C ./libft clean
	/bin/rm -f $(OUTPUT)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
