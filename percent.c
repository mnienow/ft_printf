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
	zeus->sign = 0;
	zeus->sharp = 0;
	zeus->space = 0;
	zeus->zero = 0;
	zeus->min_width = 0;
	zeus->precision = 0;
	zeus->len = zeus->len + 0;
}

char	*spaces(int i, t_mod *zeus)
{
	char	*space;

	space = (char *)malloc(i + 1);
	space[i] = 0;
	if (zeus->sign >= 0)
		space[--i] = '%';
	while (--i)
		space[i] = 32;
	if (zeus->sign < 0)
		space[0] = '%';
	else
		space[0] = 32;
	return (space);
}

void	number(const char *format, char **str, size_t *i, t_mod *zeus)
{
	char	*ad;
	char	*tmp;
	int		j;

	j = 0;
	ad = ft_strnew(0);
	while (format[i[0]] >= 48 && format[i[0]] <= 57)
		add(&ad, format[i[0]++], 0);
	if ((j = ft_atoi(ad)) != 0)
	{
		if (format[*i] == '%')
		{
			tmp = *str;
			free(ad);
			ad = spaces(j, zeus);
			*str = strnnjoin(*str, ad, zeus->len +
			ft_strlen(&str[0][zeus->len]), 0);
			free(tmp);
			zeus->len += j;
		}
		else
			zeus->min_width = j;
	}
	free(ad);
}

void	parser2(char format, char **str, va_list ap, t_mod *zeus)
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

char	*parser1(va_list ap, const char *format, size_t *ret)
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
			i = text(format, &str, i, &zeus);
		if (format[i++] == '%')
		{
			new_zeus(&zeus);
			while (format[i] == 32 || format[i] == 48 ||
			format[i] == 35 || format[i] == 43 || format[i] == 45)
			{
				zeus.space = (format[i] == 32 ? format[i++] - 31 : zeus.space);
				zeus.zero = (format[i] == 48 ? format[i++] - 47 : zeus.zero);
				zeus.sharp = (format[i] == 35 ? format[i++] - 34 : zeus.sharp);
				zeus.sign = (format[i] == 43 || format[i] == 45
				? -(format[i++] - 44) : zeus.sign);
			}
			if (format[i] >= 49 && format[i] <= 57)
				number(format, &str, &i, &zeus);
			else
			{
				if (format[i] == '%')
					add(&str, format[i], zeus.len);
			}
			parser2(format[i++], &str, ap, &zeus);
		}
	}
	*ret = zeus.len;
	return (str);
}
