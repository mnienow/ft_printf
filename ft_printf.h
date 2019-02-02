/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:27:42 by mnienow           #+#    #+#             */
/*   Updated: 2019/02/02 18:53:52 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "libft/includes/libft.h"

typedef struct	s_flag
{
	char	h;
	char	l;
	char	hh;
	char	ll;
}		t_flag;

int		ft_printf(const char *format, ...);
size_t	count(int n);
void	add(char **a, char b);
void	inta(va_list ap, char **str);
size_t	percent(const char *format, char **str, va_list ap);
size_t	ch(va_list ap, char **str);
void	ar(va_list ap, char **str);
void    pointer(va_list ap, char **str);
size_t 	text(const char *format, char **str, size_t i);
void	ft_hexadecimal(va_list ap, char **str);

#endif
