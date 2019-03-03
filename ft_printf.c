/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:02:07 by mnienow           #+#    #+#             */
/*   Updated: 2019/02/02 18:53:50 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	text(const char *format, char **str, size_t i, t_mod *zeus)
{
	char	*ad;
	char	*tmp;
	int		j;

	j = 0;
	ad = ft_strnew(0);
	while (format[i] != '%' && format[i])
	{
		add(&ad, format[i++], 0);
		j++;
	}
	tmp = *str;
	*str = strnnjoin(*str, ad, zeus->len, 0);
	zeus->len += j;
	free(tmp);
	free(ad);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;
	char	*str;
	size_t	size;
	int		i;

	i = 0;
	ret = 0;
	va_start(ap, format);
	str = parser1(ap, format, &ret);
	va_end(ap);
	size = ft_strlen(&str[ret]);
	ret = ret + size;
	write (1, str, ret);
	free(str);
	return (ret);
}
