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

static char	*ch_width(char *str, t_mod *zeus)
{
	char	*str_spaces;
	char	*tmp;
	int		width;

	width = zeus->min_width - 1;
	str_spaces = (char *)malloc(sizeof(char) * (width + 1));
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	tmp = str;
	if (zeus->sign < 0)
		str = strnnjoin(str, str_spaces, 0, 0);
	else
		str = strnnjoin(str_spaces, str, 0, 0);
	free(tmp);
	free(str_spaces);
	return (str);
}

void		ft_ch(char **str, t_mod *zeus, va_list ap)
{
	char	ch;
	char	*ar;

	ar = ft_strnew(0);
	ch = (char)va_arg(ap, unsigned int);
	add(&ar, ch, 0);
	if (zeus->min_width > 1)
		ar = ch_width(ar, zeus);
	*str = (ch == 0 ? strnnjoin(*str, ar, zeus->len, ft_strlen(&ar[ABS(zeus->sign)])
	+ 1) : strnnjoin(*str, ar, zeus->len, 0));
	zeus->len = (ch == 0 ? zeus->len + ft_strlen(&ar[ABS(zeus->sign)])
	+ 1 : zeus->len + ft_strlen(ar));
	free(ar);
}
