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

char	*spaces(int i)
{
	char *space;

	space = (char *)malloc(i + 1);
	space[i] = '\0';
	while (space[--i])
		space[i] = ' ';
	return (space);
}

size_t	text(const char *format, char **str, size_t i)
{
	char	*ad;
	size_t	size;
	char	*tmp;

	size = ft_strlen(format);
	ad = ft_strnew(0);
	while (format[i] != '%' && i < size)
		add(&ad, format[i++]);
	// 	if ((j = ft_atoi(ad) != 0) && format[i] == '%')
	// 		{
	// 			tmp = ft_strdup("%");
	// 			ad = spaces(j);
	// 			ad = (j > 0 ? ft_strjoin(ad, tmp): ft_strjoin(tmp, ad));
	// 			free(tmp);
	// 		}
	tmp = *str;
	*str = ft_strjoin(*str, ad);
	free(tmp);
	free(ad);
	return (--i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	size_t	ret;
	size_t	i;

	str = ft_strnew(0);
	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			i = text(format, &str, i);
		if (format[i++] == '%')
		{
			while (format[i] == ' ')
				i++;
			if (format[i] == 43 || format[i] == 45 || (format[i] >= '0' && format[i] <= '9'))
				i = text(format, &str, i);
			if (format[i] == '%')
			 	add(&str, format[i]);
			ret = ret + percent(&format[i++], &str, ap, &i);
																								//mb func(format, str, ap, ret);
		}
	}
	va_end(ap);
	ret = ret  + ft_strlen(str);
	write (1, str, ft_strlen(str));
	free(str);
	return (ret);
}
