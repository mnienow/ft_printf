/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:07:24 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:45:30 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	new_zeus(t_mod *zeus)
{
	zeus->flag = 0;
	zeus->alpha = 0;
	zeus->plus = 0;
	zeus->minus = 0;
	zeus->sharp = 0;
	zeus->space = 0;
	zeus->zero = 0;
	zeus->min_width = 0;
	zeus->precision = 0;
	zeus->len = zeus->len + 0;
}

void	number(const char *format, size_t *i, t_mod *zeus)
{
	char	*ad;
	char	ch;

	ch = format[i[0] - 1];
	ad = ft_strnew(0);
	while (format[i[0]] >= 48 && format[i[0]] <= 57)
		add(&ad, format[i[0]++], 0);
	if (ch == 46)
		zeus->precision = ft_atoi(ad);
	else
		zeus->min_width = ft_atoi(ad);
	free(ad);
}

void	flags1(const char *format, size_t *i, t_mod *zeus)
{
	while (format[i[0]] == 32 || (format[i[0]] >= 48 && format[i[0]] <= 57) ||
	format[i[0]] == 35 || format[i[0]] == 43 ||
	format[i[0]] == 45 || format[i[0]] == 46)
	{
		zeus->space = (format[i[0]] == 32 ? format[i[0]++] - 31 : zeus->space);
		zeus->zero = (format[i[0]] == 48 ? format[i[0]++] - 47 : zeus->zero);
		zeus->sharp = (format[i[0]] == 35 ? format[i[0]++] - 34 : zeus->sharp);
		zeus->minus = (format[i[0]] == 45 ? format[i[0]++] - 44 : zeus->minus);
		zeus->plus = (format[i[0]] == 43 ? format[i[0]++] - 42 : zeus->plus);
		if (format[i[0]] == 46)
			i[0]++;
		if (format[i[0]] >= 49 && format[i[0]] <= 57)
			number(format, i, zeus);
	}
}

void	conversions(char format, char **str, va_list ap, t_mod *zeus)
{
	if (format == 'd')
		ft_int(str, zeus, ap);
	if (format == 'c')
		ft_ch(str, zeus, ap);
	if (format == 's')
		ft_ar(str, zeus, ap);
	if (format == 'x' || format == 'X')
	{
		zeus->alpha = (format == 'x' ? 0 : 1);
		ft_hex(str, zeus, ap);
	}
	if (format == 'p')
		ft_pnt(str, zeus, ap);
	if (format == 'o')
		ft_oct(str, zeus, ap);
	if (format == 'u')
		ft_udc(str, zeus, ap);
	if (format == 'f')
		ft_dbl(str, zeus, ap);
}

char	*parser(va_list ap, const char *format, size_t *ret)
{
	char	*str;
	size_t	i;
	t_mod	zeus;

	zeus.len = 0;
	str = ft_strnew(0);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%' && format[i] && i < ft_strlen(format))
			text(format, &str, &i, &zeus);
		if (format[i++] == '%')
		{
			new_zeus(&zeus);
			flags1(format, &i, &zeus);
			if (format[i] == '%')
				percent(&str, &i, &zeus);
			flags2(format, &i, &zeus);
			conversions(format[i++], &str, ap, &zeus);
		}
	}
	*ret = zeus.len;
	return (str);
}
