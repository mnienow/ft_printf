/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:26:26 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/10 16:26:28 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pnt_width(char *str, t_mod *zeus)
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

static char	*pnt_precision(char *str, t_mod *zeus, int i)
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
	while (--count >= 0)
		str_zero[count] = '0';
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

static char	*pnt_sharp(char *str)
{
	char	*str_sharp;
	char	*tmp;

	str_sharp = ft_strdup("0x");
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	free(str_sharp);
	return (str);
}

void		ft_pnt(char **str, t_mod *zeus, va_list ap)
{
	unsigned long int	hex;
	char				*strn;
	size_t				sz;

	hex = va_arg(ap, unsigned long long);
	strn = ft_itoal(hex, 16, zeus);
	if (hex == 0)
	{
		free(strn);
		strn = ft_strdup("0");
	}
	if (zeus->precision != 1)
		strn = pnt_precision(strn, zeus, 1);
	if (1)
		strn = pnt_sharp(strn);
	if (zeus->zero && zeus->precision == 1 && zeus->min_width)
		strn = pnt_precision(strn, zeus, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = pnt_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
