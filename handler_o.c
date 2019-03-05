/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:38:04 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/05 16:38:06 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*oct_width(char *str, t_mod *zeus)
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

static char		*oct_precision(char *str, t_mod *zeus, int i, intmax_t hex)
{
	char	*str_zero;
	char	*tmp;
	int		count;

	if (i)
		count = zeus->precision - ft_strlen(str);
	else
		count = zeus->min_width - ft_strlen(str);
	str_zero = (char *)malloc(sizeof(char) * (count + 1));
	str_zero[count] = '\0';
	if (hex != 0)
	{
		while (--count >= 0)
			str_zero[count] = '0';
	}
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

static char		*oct_sharp(char *str)
{
	char	*str_sharp;
	char	*tmp;

	str_sharp = "0";
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	return (str);
}

void			ft_oct(char **str, t_mod *zeus, va_list ap)
{
	intmax_t	hex;
	char		*string;
	char		*tmp;

	hex = va_arg(ap, int);
	if (zeus->flag == 1)
		hex = (unsigned short)hex;
	if (zeus->flag == 2)
		hex = (unsigned long)hex;
	if (zeus->flag == 3)
		hex = (unsigned char)hex;
	if (zeus->flag == 4)
		hex = (unsigned long long)hex;
	// if (hex != 0 || zeus->sharp || (zeus->min_width == 0 && zeus->precision == 0))
		string = ft_itoal(hex, 8, zeus);
	// else
	// 	string = ft_strdup("");
	if (zeus->precision)
		string = oct_precision(string, zeus, 1, hex);
	if (zeus->sharp && hex != 0)
		string = oct_sharp(string);
	if (zeus->zero && !(zeus->precision) && !(zeus->minus)
	&& !(zeus->plus) && zeus->min_width)
		string = oct_precision(string, zeus, 0, hex);
	if (zeus->min_width > (int)ft_strlen(string))
		string = oct_width(string, zeus);
	tmp = *str;
	*str = strnnjoin(*str, string, zeus->len, 0);
	zeus->len += ft_strlen(string);
	free(tmp);
	free(string);
}
