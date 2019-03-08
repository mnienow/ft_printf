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

static __int128_t	expo(int i)
{
	__int128_t	expt;

	expt = 10;
	while (i--)
		expt = expt * 10;
	return (expt);
}

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

static char			*dbl_precision(char *str, t_mod *zeus, int i)
{
	char	*str_zero;
	char	*tmp;
	int		count;
	size_t	sz;

	sz = ft_strlen(str);
	count = (i != 0 ? zeus->precision - sz : zeus->min_width - sz);
	if (count < 0)
		return (str);
	str_zero = (char *)malloc(count + 1);
	str_zero[count] = '\0';
	while (--count >= 0)
		str_zero[count] = '0';
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

void				ft_dbl(char **str, t_mod *zeus, va_list ap)
{
	double		nbr;
	int			prc;
	char		*strn;
	size_t		sz;

	prc = 6;
	if (zeus->precision != 1)
		prc = zeus->precision;
	nbr = (zeus->flag == 5 ? va_arg(ap, long double) : va_arg(ap, double));
	zeus->alpha = 0;
	strn = ft_itoal((long long int)nbr, 10, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
	nbr = ABS(nbr);
	nbr = (nbr - (long long int)nbr) * expo(prc - 1) + 0.5;
	*str = strnnjoin(*str, ft_strdup("."), zeus->len++, 0);
	strn = ft_itoal((long long int)nbr, 10, zeus);
	if (zeus->zero)
		strn = dbl_precision(strn, zeus, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = dbl_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
