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

static char	*ar_precision(char *str, t_mod *zeus)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(zeus->precision + 1);
	while (i < zeus->precision)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void		ft_ar(char **str, t_mod *zeus, va_list ap)
{
	char	*arr;
	char	*tmp;

	arr = va_arg(ap, char *);
	arr = (arr == NULL ? ft_strdup("(null)") : arr);
	if (zeus->precision)
		arr = ar_precision(arr, zeus);
	if (zeus->min_width > ft_strlen(arr))
		arr = ar_width(arr, zeus);
	tmp = *str;
	*str = strnnjoin(*str, arr, zeus->len, 0);
	zeus->len += ft_strlen(arr);
	free(tmp);
	if (zeus->precision || zeus->min_width)
		free(arr);
}
