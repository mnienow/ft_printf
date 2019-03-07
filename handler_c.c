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

static void	ch_width(char **str, t_mod *zeus)
{
	char	*str_spaces;
	int		width;

	width = zeus->min_width - 1;
	str_spaces = (char *)malloc(width + 1);
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	if (zeus->minus)
		*str = strnnjoin(*str, str_spaces, 1, 0);
	else
		*str = strnnjoin(str_spaces, *str, 0, 1);
}

void		ft_ch(char **str, t_mod *zeus, va_list ap)
{
	char	ch;
	char	*ar;
	size_t	sz;

	ar = ft_strnew(0);
	ch = (char)va_arg(ap, unsigned int);
	add(&ar, ch, 0);
	if (zeus->min_width > 1)
		ch_width(&ar, zeus);
	*str = (ch == 0 ? strnnjoin(*str, ar, zeus->len, zeus->min_width)
	: strnnjoin(*str, ar, zeus->len, 0));
	sz = (zeus->min_width == 0 ? 1 : zeus->min_width);
	zeus->len += sz;
}
