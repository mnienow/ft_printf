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

void	percent(const char *format, char **str, va_list ap)
{
	if (*format	== 'd')
		*str = inta(ap, *str);
	if (*format == 'c')
		*str = ch(ap, *str);
	if (*format == 's')
		*str = ar(ap, *str);
}
