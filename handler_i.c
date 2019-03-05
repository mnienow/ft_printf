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

static char	*int_precision(char *str, t_mod *zeus, int i)
{
	char	*str_zero;
	char	*tmp;
	int		count;
	size_t	sz;

	sz = ft_strlen(str);
	count = (i != 0 ? zeus->precision - sz : zeus->min_width - sz);
	str_zero = (char *)malloc(sizeof(char) * (count + 1));
	str_zero[count] = '\0';
	while (--count >= 0)
		str_zero[count] = '0';
	str_zero[0] = (str[0] == '-' ? '-' : str_zero[0]);
	str[0] = (str[0] == '-' ? '0' : str[0]);
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

void		ft_int(char **str, t_mod *zeus, va_list ap)
{
	int		integer;
	char	*string;
	char	*tmp;

	integer = va_arg(ap, int);
	string = ft_itoa(integer);
	string = (zeus->precision == 0 ? string : int_precision(string, zeus, 1));
	if (zeus->zero && !(zeus->precision) && zeus->min_width && !(zeus->minus))
		string = int_precision(string, zeus, 0);
	if (zeus->plus && integer >= 0)
	{
		if (!zeus->zero)
			string = ft_strjoin("+", string);
		else
			string[0] = '+';
	}
	if (!zeus->plus && zeus->space && integer >= 0)
		string = ft_strjoin(" ", string);
	if (zeus->min_width > (int)ft_strlen(string))
		string = int_width(string, zeus);
	tmp = *str;
	*str = strnnjoin(*str, string, zeus->len, 0);
	zeus->len += ft_strlen(string);
	free(string);
	free(tmp);
}
