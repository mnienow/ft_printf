/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:38:04 by sstannis          #+#    #+#             */
/*   Updated: 2019/03/05 14:27:30 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*dbl_width(char *str, t_mod *zeus)
{
	char	*str_spaces;
	char	*tmp;
	int		width;

	width = zeus->min_width - ft_strlen(str);
	str_spaces = (char *)malloc(sizeof(char) * (width + 1));
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	tmp = str;
	if (zeus->minus)
		str = ft_strjoin(str, str_spaces);
	else
		str = ft_strjoin(str_spaces, str);
	free(tmp);
	free(str_spaces);
	return (str);
}

static char			*dbl_precision(char *s, t_mod *zeus, int i)
{
	char	*s0;
	int		count;
	size_t	sz;

	sz = !ft_strchr(s, '.') ? ft_strlen(s) : ft_strlen(ft_strchr(s, '.') + 1);
	sz = (s[0] != '-' && zeus->plus) || zeus->space ? sz + 1 : sz;
	if (i)
		count = i == 2 ? zeus->nprec - 2 : zeus->precision - sz;
	else
		count = zeus->min_width - sz;
	if (count <= 0)
		return (s);
	s0 = (char *)malloc(count + 1);
	s0[count] = '\0';
	while (--count >= 0)
		s0[count] = '0';
	s0[0] = s[0] == '-' && !i ? '-' : s0[0];
	s[0] = s[0] == '-' && !i ? '0' : s[0];
	s = i == 1 ? strnnjoin(s, s0, 0, 0) : strnnjoin(s0, s, 0, 0);
	return (s);
}

void				ft_dbl(char **str, t_mod *zeus, va_list ap)
{
	long double	nbr;
	char		*strn;
	size_t		sz;

	zeus->precision = (zeus->dot ? zeus->precision : 6);
	nbr = va_arg(ap, long double);
	zeus->flag == 5 ? nbr = (double)nbr : 0;
	strn = ft_itoal(nbr, 10, zeus);
	while (nbr != (long long)nbr && zeus->nprec++)
		nbr *= 10.0000000000000000001;
	strn = !zeus->precision ? strn : strnnjoin(strn, ft_strdup("."), 0, 0);
	strn = !zeus->precision ? strn : strnnjoin(strn, dbl_precision(ft_itoal(nbr,
	10, zeus), zeus, 2), 0, 0);
	strn = !zeus->precision ? strn : dbl_precision(strn, zeus, 1);
	strn = zeus->zero ? dbl_precision(strn, zeus, 0) : strn;
	if (zeus->plus && strn[0] != '-')
		strn = strnnjoin(ft_strdup("+"), strn, 0, 0);
	if (!zeus->plus && zeus->space && strn[0] != '-')
		strn = strnnjoin(ft_strdup(" "), strn, 0, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = dbl_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
