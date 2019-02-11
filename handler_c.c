/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:19:34 by mnienow           #+#    #+#             */
/*   Updated: 2019/02/11 21:19:37 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ch(va_list ap, char **str)
{
	char	ch;
	size_t	ret;

	ch = (char)va_arg(ap, unsigned int);
    // *str = (ch == 0 ? : add(str, ch));
    // ret = (ch == 0 ? (ret + 1) : ret);
	ret = ft_strlen(*str);
	if (ch == 0)
	{
		write (1, *str, ret);
		ret = ret + 1;
		write (1, "\0", 1);
		free(*str);
		*str = ft_strnew(0);
	}
	else
		add(str, ch);
	return (ret);
}
