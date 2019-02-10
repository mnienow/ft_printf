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

void    new_zeus(t_mod    *zeus)
{
    zeus->flag = 0;
	zeus->alpha = 0;
    zeus->minus = 0;
    zeus->plus = 0;
    zeus->sharp = 0;
    zeus->space = 0;
    zeus->zero = 0;
    zeus->min_width = 0;
    zeus->precision = 0;
}

char	*spaces(int i)
{
	char	*space;
	int 	n;

	n = i;
	i = ABS(i);
	space = (char *)malloc(i + 1);
	space[i] = 0;
	if (n > 0)
		space[--i] = '%';
	while (--i)
		space[i] = 32;
	if (n < 0)
		space[0] = '%';
	else
		space[0] = 32;
	return (space);
}

size_t	number(const char *format, char **str, size_t i, t_mod *zeus)
{
	char	*ad;
	char	*tmp;
	int		j;
	
	j = 0;
	ad = ft_strnew(0);
	while (format[i] == 43 || format[i] == 45 || (format[i]>= 48 && format[i]<= 57))
	{
		zeus->plus = (format[i] == 43 ? 1 : zeus->plus);
		zeus->minus = (format[i] == 45 ? 1: zeus->minus);
		add(&ad, format[i++]);
	}
	if ((j = ft_atoi(ad)) != 0)
	{
		if (format[i] == '%')
		{
			tmp = *str;
			free(ad);
			ad = spaces(j);
			*str = ft_strjoin(*str, ad);
			free(tmp);
		}
		else
			zeus->min_width = ABS(j);
	}
	free(ad);
	return (i);
}

size_t	parser2(char format, char **str, va_list ap, t_mod *zeus)
{
	size_t	ret;

	ret = 0;
	if (format == 'd')
		inta(ap, str);
    if (format == 'c')
		ret = ret + ch(ap, str);
	if (format == 's')
		ar(ap, str);
	if (format == 'x' || format == 'X')
	{
		zeus->alpha = (format == 'x' ? 0 : 1);
		ft_hex(str, zeus, ap);
	}
	if (format == 'p')
		pointer(ap, str);
	if (format == 'o')
		ft_oct(str, zeus, ap);
	return (ret);
}

char    *parser1(va_list ap, const char *format, size_t *ret)
{
    char    *str;
    size_t  i;
    t_mod   zeus;

    str = ft_strnew(0);
    i = 0;
    while (format[i])
    {
        if (format[i] != '%' && format[i])
            i = text(format, &str, i);
        if (format[i++] == '%')
        {
            new_zeus(&zeus);
            while (format[i] == 32)
                zeus.space = format[i++] - 31;
            while (format[i] == 35)
                zeus.sharp = format[i++] - 34;
            while (format[i] == 48)
                zeus.zero = format[i++] + 1;
            if (format[i] == 43 || format[i] == 45 || (format[i] >= 49 && format[i] <= 57))
				i = number(format, &str, i, &zeus);
            else
            {
                if (format[i] == '%')
                    add(&str, format[i]);
            }
            *ret = *ret + parser2(format[i++], &str, ap, &zeus);
        }
    }
    return (str);
}