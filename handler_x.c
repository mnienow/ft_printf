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

static void	flag(t_mod *zeus, unsigned long long int *hex)
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

char		*hex_prec(char *str, t_mod *zeus, int i)
{
	char	*str_zero;
	int		count;
	size_t	sz;

	sz = ft_strlen(str);
	count = (i != 0 ? zeus->precision - sz : zeus->min_width - sz);
	if (count <= 0)
		return (str);
	str_zero = (char *)malloc(count + 2);
	str_zero[++count] = '\0';
	str_zero[--count] = '\0';
	i = 0;
	while (i < count)
		str_zero[i++] = '0';
	str_zero[1] = (str[1] == 'x' || str[1] == 'X' ? str[1] : str_zero[1]);
	str[1] = (str[1] == 'x' || str[1] == 'X' ? '0' : str[1]);
	i = 0;
	if (count == 1 && zeus->sharp && str_zero[1])
		while (str[i++])
			str[i] = str[i + 1];
	str = strnnjoin(str_zero, str, 0, 0);
	return (str);
}

char		*hex_sharp(char *str, t_mod *zeus)
{
	char	*str_sharp;
	char	*tmp;

	str_sharp = (zeus->alpha == 0 ? ft_strdup("0x") : ft_strdup("0X"));
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	free(str_sharp);
	return (str);
}

void		ft_hex(char **str, t_mod *zeus, va_list ap)
{
	unsigned long long int		hex;
	char						*strn;
	size_t						sz;

	hex = (unsigned long long int)va_arg(ap, unsigned long long int);
	flag(zeus, &hex);
	if (hex == 0 && zeus->dot && zeus->precision != 1 && !zeus->sharp)
		strn = ft_strdup("");
	else
		strn = ft_uitoal(hex, 16, zeus);
	if (zeus->dot)
		strn = hex_prec(strn, zeus, 1);
	if (zeus->sharp && hex != 0)
		strn = hex_sharp(strn, zeus);
	if (zeus->zero && !zeus->dot && zeus->min_width && !(zeus->minus))
		strn = hex_prec(strn, zeus, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = hex_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
