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
	zeus->precision = 1;
	zeus->min_width = 0;
	zeus->len = zeus->len + 0;
}

void	number(const char *fmt, size_t *i, t_mod *zeus)
{
	char	*ad;

	ad = ft_strnew(0);
	while (fmt[i[0]] >= 48 && fmt[i[0]] <= 57)
		add(&ad, fmt[i[0]++], 0);
	if (zeus->dot)
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
		if ((fmt[i[0]] >= 49 && fmt[i[0]] <= 57) || (fmt[i[0]] == 48 && zeus->dot))
			number(fmt, i, zeus);
	}
}

size_t	conversions(const char *fmt, char **str, va_list ap, t_mod *zeus)
{
	char ch;

	ch = fmt[1];
	zeus->precision = (fmt[0] == 46 ? 0 : zeus->precision);
	conversions2(&ch, zeus);
	if (ch == 'd' || ch == 'i')
		ft_int(str, zeus, ap);
	if (ch == 'c')
		ft_ch(str, zeus, ap);
	if (ch == 's')
		ft_ar(str, zeus, ap);
	if (ch == 'x')
		ft_hex(str, zeus, ap);
	if (ch == 'p')
		ft_pnt(str, zeus, ap);
	if (ch == 'o')
		ft_oct(str, zeus, ap);
	if (ch == 'u')
		ft_udc(str, zeus, ap);
	if (ch == 'f')
		ft_dbl(str, zeus, ap);
	if (ch == 'd' || ch == 'i' || ch == 'c' || ch == 's' || ch == 'x'
	|| ch == 'p' || ch == 'o' || ch == 'u' || ch == 'f')
		return (1);
	return (0);
}

char	*parser(va_list ap, const char *fmt, size_t *ret)
{
	char	*str;
	size_t	i;
	size_t	sz;
	t_mod	zeus;

	zeus.len = 0;
	str = ft_strnew(0);
	i = 0;
	sz = ft_strlen(fmt);
	while (i < sz)
	{
		if (fmt[i] != '%' && i < sz)
			text(fmt, &str, &i, &zeus);
		if (fmt[i++] == '%')
		{
			new_zeus(&zeus);
			flags1(fmt, &i, &zeus);
			if (fmt[i] == '%')
				percent(&str, &i, &zeus);
			flags2(fmt, &i, &zeus);
			i += conversions(&fmt[i - 1], &str, ap, &zeus);
		}
	}
	*ret = zeus.len;
	return (str);
}
