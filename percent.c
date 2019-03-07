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
	zeus->dot = 0;
	zeus->precision = 0;
	zeus->min_width = 0;
	zeus->len = zeus->len + 0;
}

void	number(const char *fmt, size_t *i, t_mod *zeus)
{
	char	*ad;
	char	ch;

	ch = fmt[i[0] - 1];
	ad = ft_strnew(0);
	while (fmt[i[0]] >= 48 && fmt[i[0]] <= 57)
		add(&ad, fmt[i[0]++], 0);
	if (ch == 46)
		zeus->precision = ft_atoi(ad);
	else
		zeus->min_width = ft_atoi(ad);
	free(ad);
}

void	flags1(const char *fmt, size_t *i, t_mod *zeus)
{
	while ((fmt[i[0]] >= 48 && fmt[i[0]] <= 57) || fmt[i[0]] == 32 ||
	fmt[i[0]] == 35 || fmt[i[0]] == 43 || fmt[i[0]] == 45 || fmt[i[0]] == 46)
	{
		zeus->space = (fmt[i[0]] == 32 ? fmt[i[0]++] - 31 : zeus->space);
		zeus->zero = (fmt[i[0]] == 48 ? fmt[i[0]++] - 47 : zeus->zero);
		zeus->sharp = (fmt[i[0]] == 35 ? fmt[i[0]++] - 34 : zeus->sharp);
		zeus->minus = (fmt[i[0]] == 45 ? fmt[i[0]++] - 44 : zeus->minus);
		zeus->plus = (fmt[i[0]] == 43 ? fmt[i[0]++] - 42 : zeus->plus);
		zeus->dot = (fmt[i[0]] == 46 ? fmt[i[0]++] - 45 : zeus->dot);
		if (fmt[i[0]] >= 49 && fmt[i[0]] <= 57)
			number(fmt, i, zeus);
	}
}

void	conversions(char fmt, char **str, va_list ap, t_mod *zeus)
{
	if (fmt == 'd')
		ft_int(str, zeus, ap);
	if (fmt == 'c')
		ft_ch(str, zeus, ap);
	if (fmt == 's')
		ft_ar(str, zeus, ap);
	if (fmt == 'x' || fmt == 'X')
	{
		zeus->alpha = (fmt == 'x' ? 0 : 1);
		ft_hex(str, zeus, ap);
	}
	if (fmt == 'p')
		ft_pnt(str, zeus, ap);
	if (fmt == 'o')
		ft_oct(str, zeus, ap);
	if (fmt == 'u')
		ft_udc(str, zeus, ap);
	if (fmt == 'f')
		ft_dbl(str, zeus, ap);
}

char	*parser(va_list ap, const char *fmt, size_t *ret)
{
	char	*str;
	size_t	i;
	t_mod	zeus;

	zeus.len = 0;
	str = ft_strnew(0);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%' && fmt[i] && i < ft_strlen(fmt))
			text(fmt, &str, &i, &zeus);
		if (fmt[i++] == '%')
		{
			new_zeus(&zeus);
			flags1(fmt, &i, &zeus);
			if (fmt[i] == '%')
				percent(&str, &i, &zeus);
			flags2(fmt, &i, &zeus);
			conversions(fmt[i++], &str, ap, &zeus);
		}
	}
	*ret = zeus.len;
	return (str);
}
