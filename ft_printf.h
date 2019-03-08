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
# include <limits.h>
# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# define ABS(number) ((number) > 0 ? (number):-(number))

typedef enum		e_flags
{
	hy,
	h,
	l,
	hh,
	ll,
	L
}					t_flags;

typedef struct		s_mod
{
	enum e_flags	flag;
	int				alpha;
	int				plus;
	int				minus;
	int				sharp;
	int				space;
	int				zero;
	int				dot;
	int				precision;
	size_t			min_width;
	size_t			len;
}					t_mod;

int					ft_printf(const char *format, ...);
void				add(char **a, char b, size_t sz);
void				text(const char *format, char **str,
size_t *i, t_mod *zeus);
size_t				sign(const char *format, size_t i, t_mod *zeus);
char				*parser(va_list ap, const char *format, size_t *ret);
char				*ft_itoal(__int128_t nb, int base, t_mod *zeus);
char				*ft_uitoal(unsigned long long int nb, int base,
t_mod *zeus);
void				ft_ch(char **str, t_mod *zeus, va_list ap);
void				ft_int(char **str, t_mod *zeus, va_list ap);
void				ft_ar(char **str, t_mod *zeus, va_list ap);
void				ft_hex(char **str, t_mod *zeus, va_list ap);
void				ft_oct(char **str, t_mod *zeus, va_list ap);
void				ft_udc(char **str, t_mod *zeus, va_list ap);
void				ft_pnt(char **str, t_mod *zeus, va_list ap);
char				*strnnjoin(char *s1, char *s2, size_t sz1, size_t sz2);
void				ft_dbl(char **str, t_mod *zeus, va_list ap);
void				percent(char **str, size_t *i, t_mod *zeus);
void				flags2(const char *format, size_t *i, t_mod *zeus);
void				conversions2(char *fmt, t_mod *zeus);
#endif
