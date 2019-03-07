/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:21:42 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:47:22 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag(t_mod *zeus, intmax_t *inta)
{
	if (!zeus->flag)
		*inta = (int)*inta;
	if (zeus->flag == 1)
		*inta = (short)*inta;
	if (zeus->flag == 2)
		*inta = (long)*inta;
	if (zeus->flag == 3)
		*inta = (signed char)*inta;
	if (zeus->flag == 4)
		*inta = (long long)*inta;
}

static char	*int_width(char *str, t_mod *zeus)
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
	str = (zeus->minus != 0 ? ft_strjoin(str, str_spaces)
	: ft_strjoin(str_spaces, str));
	free(tmp);
	free(str_spaces);
	return (str);
}

static char	*int_precision(char *str, t_mod *zeus, int i, intmax_t integer)
{
	char	*str_zero;
	char	*tmp;
	int		count;
	size_t	sz;

	sz = ft_strlen(str);
	count = (i != 0 ? zeus->precision - sz : zeus->min_width - sz);
	if (count < 0)
		return (str);
	str_zero = (char *)malloc(sizeof(char) * (count + 1));
	str_zero[count] = '\0';
	if ((integer != 0) || (integer == 0 && zeus->precision))
		while (--count >= 0)
			str_zero[count] = '0';
	if (zeus->precision)
		str_zero = (str[0] == '-' ? ft_strjoin("-", str_zero) : str_zero);
	else if (zeus->min_width && str[0] == '-')
		str_zero[0] = '-';
	str[0] = (str[0] == '-' ? '0' : str[0]);
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

void		ft_int(char **str, t_mod *zeus, va_list ap)
{
	intmax_t		inta;
	char			*strn;
	char			*tmp;

	inta = va_arg(ap, intmax_t);
	flag(zeus, &inta);
	strn = ft_itoal(inta, 10, zeus);
	strn = (zeus->precision == 0 ? strn : int_precision(strn, zeus, 1, inta));
	if (zeus->zero && !(zeus->precision) && zeus->min_width && !(zeus->minus))
		strn = int_precision(strn, zeus, 0, inta);
	if (zeus->plus && inta >= 0)
	{
		if (!zeus->zero)
			strn = ft_strjoin("+", strn);
		else
			strn[0] = '+';
	}
	if (!zeus->plus && zeus->space && inta >= 0)
		strn = ft_strjoin(" ", strn);
	strn = (zeus->min_width > ft_strlen(strn) ? int_width(strn, zeus) : strn);
	tmp = *str;
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += ft_strlen(strn);
	free(strn);
	free(tmp);
}
