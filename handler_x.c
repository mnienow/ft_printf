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

static void	flag(t_mod *zeus, intmax_t *hex)
{
	if (!zeus->flag)
		*hex = (unsigned int)*hex;
	if (zeus->flag == 1)
		*hex = (unsigned short)*hex;
	if (zeus->flag == 2)
		*hex = (unsigned long)*hex;
	if (zeus->flag == 3)
		*hex = (unsigned char)*hex;
	if (zeus->flag == 4)
		*hex = (unsigned long long)*hex;
}

char		*hex_width(char *str, t_mod *zeus)
{
	char	*str_spaces;
	int		width;

	width = zeus->min_width - ft_strlen(str);
	str_spaces = (char *)malloc(sizeof(char) * (width + 1));
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	if (zeus->minus)
		str = ft_strjoin(str, str_spaces);
	else
		str = ft_strjoin(str_spaces, str);
	free(str_spaces);
	return (str);
}

char		*hex_precision(char *str, t_mod *zeus, int i, intmax_t hex)
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
	if (hex != 0)
		while (--count >= 0)
			str_zero[count] = '0';
	str_zero[1] = (str[1] == 'x' || str[1] == 'X' ? str[1] : str_zero[1]);
	str[1] = (str[1] == 'x' || str[1] == 'X' ? '0' : str[1]);
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

char		*hex_sharp(char *str, t_mod *zeus)
{
	char	*str_sharp;
	char	*tmp;

	str_sharp = (zeus->alpha == 0 ? "0x" : "0X");
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	return (str);
}

void		ft_hex(char **str, t_mod *zeus, va_list ap)
{
	intmax_t		hex;
	char			*string;
	char			*tmp;

	hex = va_arg(ap, intmax_t);
	flag(zeus, &hex);
	if (hex < 0)
		hex = 4294967295 + 1 + hex;
	if (hex == 0 && zeus->dot)
		string = ft_strdup("");
	else
		string = ft_itoal(hex, 16, zeus);
	if (zeus->precision)
		string = hex_precision(string, zeus, 1, hex);
	if (zeus->sharp && hex != 0)
		string = hex_sharp(string, zeus);
	if (zeus->zero && !(zeus->precision) && zeus->min_width && !(zeus->minus))
		string = hex_precision(string, zeus, 0, hex);
	if (zeus->min_width > ft_strlen(string))
		string = hex_width(string, zeus);
	tmp = *str;
	*str = strnnjoin(*str, string, zeus->len, 0);
	zeus->len += ft_strlen(string);
	free(tmp);
	free(string);
}
