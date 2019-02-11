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

void	ft_ch(char **str, t_mod *zeus, va_list ap)
{
	char	ch;
	size_t 	ret;

	ch = (char)va_arg(ap, unsigned int);
	if (ch == 0)
	{
		write (1, *str, (ret = ft_strlen(*str)));
		zeus->len = ret + 1;
		write (1, "\0", 1);
		free(*str);
		*str = ft_strnew(0);
	}
	else
		add(str, ch);
}
