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

size_t	text(const char *format, char **str, size_t i)
{
	char	*ad;
	char	*tmp;

	ad = ft_strnew(0);
	while (format[i] != '%' && format[i])
		add(&ad, format[i++]);
	tmp = *str;
	*str = ft_strjoin(*str, ad);
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

	ret = 0;
	va_start(ap, format);
	str = parser1(ap, format, &ret);
	va_end(ap);
	size = ft_strlen(str);
	write (1, str, size);
	free(str);
	return (ret + size);
}
