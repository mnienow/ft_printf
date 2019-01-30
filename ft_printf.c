/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:02:07 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:53:18 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*text(const char **format, char **str)
{
	char	*tmp;
	char	*tmp2;
	
	tmp = ft_strnew(0);
	tmp = add(tmp, **format);
	tmp2 = *str;
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	free(tmp2);
	return (*str);
}
/*
char	*space(const char *format, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, add(ft_strdup(""), *format));
	free(tmp);
	return (str);
}*/

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	str = ft_strnew(0);
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%' && *format != '\0')
			text(&format, &str);
		if (*format++ == '%')
		{
			/*str = (*format++ == 'd' ? inta(ap, str) : str);
			str = (*format == 'c' ? ch(ap, str) : str);*/
			while (*format == ' ')
				format++;
			if (*format == '%')
				text(&format, &str);	
			ret = ret + (int)percent(format++, &str, ap);
																								//mb func(format, str, ap, ret);
		}
	}
	va_end(ap);
	write (1, str, ft_strlen(str));
	free(str);
	return (ret + ft_strlen(str));
}
