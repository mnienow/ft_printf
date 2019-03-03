/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:49:19 by mnienow           #+#    #+#             */
/*   Updated: 2019/02/11 20:49:24 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char	*ar_width(char *str, t_mod *zeus)
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

static char	*ar_precision(char *str, t_mod *zeus, int	i)
{
	char	*str_zero;
	char	*tmp;
	int		count;

	if (i)
		count = zeus->precision - ft_strlen(str);
	else
		count =  zeus->min_width - ft_strlen(str);
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

void	ft_ar(char **str, t_mod *zeus, va_list ap)
{
	char *arr;
	char *tmp;

	arr = va_arg(ap, char *);
	arr = (arr == NULL ? ft_strdup("(null)") : arr);
	if (zeus->precision)
		arr = ar_precision(arr, zeus, 1);
	if (zeus->zero && !(zeus->precision) && zeus->min_width)
		arr = ar_precision(arr, zeus, 0);
	if (zeus->min_width > (int)ft_strlen(arr))
		arr = ar_width(arr, zeus);
	tmp = *str;
	*str = strnnjoin(*str, arr, zeus->len, 0);
	zeus->len += ft_strlen(arr);
	free(tmp);
}