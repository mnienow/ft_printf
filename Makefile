# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnienow <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/25 14:23:03 by mnienow           #+#    #+#              #
#    Updated: 2019/02/01 15:55:22 by sstannis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c add.c percent.c handler*.c itoa.c

FLAGS = -Wall -Wextra -Werror

OUTPUT = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) ./libft/ft_itoa.c ./libft/ft_memalloc.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlen.c ./libft/ft_strnew.c ./libft/ft_strdel.c ./libft/ft_atoi.c ./libft/ft_strcpy.c ./libft/ft_strchr.c ./libft/ft_abs.c -c 
	gcc $(FLAGS) $(SRCS) -c -I .
	ar rc $(NAME) $(OUTPUT)

clean:
	make -C ./libft clean
	/bin/rm -f $(OUTPUT) rm -f ft_printf.h.gch

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
