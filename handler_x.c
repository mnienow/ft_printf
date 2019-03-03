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

char	*hex_width(char *str, t_mod *zeus)
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

char    *hex_precision(char *str, t_mod *zeus, int    i)
{
    char    *str_zero;
    char    *tmp;
    int        count;

    if (i)
        count = zeus->precision - ft_strlen(str);
    else
        count =  zeus->min_width - ft_strlen(str);
    str_zero = (char *)malloc(sizeof(char)* (count + 1));
    str_zero[count] = '\0';
    while (--count >= 0)
        str_zero[count] = '0';
    tmp = str;
    str = ft_strjoin(str_zero, str);
    free(tmp);
    free(str_zero);
    return (str);
}

char    *hex_sharp(char *str, t_mod *zeus)
{
    char    *str_sharp;
    char    *tmp;

    str_sharp = (zeus->alpha == 0 ? "0x" : "0X");
    tmp = str;
    str = ft_strjoin(str_sharp, str);
    free(tmp);
    return (str);
}

void	ft_hex(char **str, t_mod *zeus, va_list ap)
{
	long long int	hex;
	char			*string;
	char			*tmp;
	
	hex = va_arg(ap, int);
	if (hex < 0)
		hex = 4294967295 + 1 + hex;
	string = ft_itoal(hex, 16, zeus);
	if (zeus->precision)
		string = hex_precision(string, zeus, 1);
	if (zeus->sharp)
		string = hex_sharp(string, zeus);
	if (zeus->zero && !(zeus->precision) && zeus->min_width)
		string = hex_precision(string, zeus, 0);
	if (zeus->min_width > (int)ft_strlen(string))
		string = hex_width(string, zeus);
	tmp = *str;
	*str = strnnjoin(*str, string, zeus->len, 0);
	zeus->len += ft_strlen(string);
	free(tmp);
	free(string);
}
