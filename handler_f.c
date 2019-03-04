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

static int      stepen(int i)
{
	int		ten;

	ten = 10;
	while (i--)
		ten = ten * 10;
	return (ten);
}

void	        ft_dbl(char **str, t_mod *zeus, va_list ap)
{
    double      number;
    int         precision;
    char		*string;

    precision = 6;
    if (zeus->precision > 0)
        precision = zeus->precision;
    number = va_arg(ap, double);
    zeus->alpha = 0;
    string = ft_itoal((int)number, 10, zeus);
    *str = ft_strjoin(*str, string);
    number = (number - (int)number) * stepen(precision - 1) + 0.5;
    *str = ft_strjoin(*str, ".");
    string = ft_itoal((int)number, 10, zeus);
    *str = ft_strjoin(*str, string);
    free(string);
}
