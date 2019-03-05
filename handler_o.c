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

static char		*oct_precision(char *str, t_mod *zeus, int i)
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
	while (--count >= 0)
		str_zero[count] = '0';
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
	long long int	hex;
	char			*string;
	char			*tmp;

	hex = va_arg(ap, int);
	string = ft_itoal(hex, 8, zeus);
	if (zeus->precision)
		string = oct_precision(string, zeus, 1);
	if (zeus->sharp)
		string = oct_sharp(string);
	if (zeus->zero && !(zeus->precision) && !(zeus->minus)
	&& !(zeus->plus) && zeus->min_width)
		string = oct_precision(string, zeus, 0);
	if (zeus->min_width > (int)ft_strlen(string))
		string = oct_width(string, zeus);
	tmp = *str;
	*str = strnnjoin(*str, string, zeus->len, 0);
	zeus->len += ft_strlen(string);
	free(tmp);
	free(string);
}
