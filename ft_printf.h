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
# define ABS(number) ((number) > 0 ? (number):-(number))

typedef enum	s_flags
{
    hy,
	h,
	l,
	hh,
	ll,
	L
}	t_flags;

typedef struct	s_mod
{
	enum	s_flags flag;
	int		minus;
	int		plus;
	int		sharp;
	int		space;
	int		zero;
	int		min_width;
	int		precision;
}		t_mod;

int		ft_printf(const char *format, ...);
size_t	count(int n);
void	add(char **a, char b);
void	inta(va_list ap, char **str);
size_t	parser2(char format, char **str, va_list ap, t_mod *zeus);
size_t	ch(va_list ap, char **str);
void	ar(va_list ap, char **str);
void    pointer(va_list ap, char **str);
size_t 	text(const char *format, char **str, size_t i);
char	*spaces(int i);
char    *parser1(va_list ap, const char *format, size_t *ret);
size_t	number(const char *format, char **str, size_t i, t_mod *zeus);
char	*ft_itoal(long long int nb, int base);
void	ft_hex(char **str, t_mod *zeus, va_list ap);
char	*hex_precision(char *str, t_mod *zeus, int	i);
char	*hex_width(char *str, t_mod *zeus);
char	*hex_sharp(char *str);

#endif
