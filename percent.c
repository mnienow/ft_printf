/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:07:24 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:45:30 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent(const char *format, char **str, va_list ap)
{
	size_t	ret;

	ret = 0;
	if (*format == 'd')
		inta(ap, str);
	//if (**format++ == '%')
	//	text(format, str);
	if (*format == 'c')
		ret = ret + ch(ap, str);
	if (*format == 's')
		ar(ap, str);
	//if (*format == 'x')
	//	ft_hexadecimal(ap, str);
	//if (*format == 'p')
	//	pointer(ap, str);
	return (ret);
}
