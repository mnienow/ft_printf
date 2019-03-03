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

void	ft_ch( char **str, t_mod *zeus, va_list ap)
{
	char	ch;
	size_t	ret;

	ch = (char)va_arg(ap, unsigned int);
	ret = ft_strlen(&str[0][zeus->len]);
	zeus->len = zeus->len + ret;
	add(str, ch, zeus->len++);
}
