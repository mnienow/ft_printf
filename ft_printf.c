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

void	flags2(const char *fmt, size_t *i, t_mod *zeus)
{
	if (fmt[i[0]] == 'h')
	{
		zeus->flag = (fmt[i[0]++ + 1] == 'h' ? hh : h);
		i[0] = (fmt[i[0]] == 'h' ? i[0] + 1 : i[0]);
	}
	if (fmt[i[0]] == 'l')
	{
		zeus->flag = (fmt[i[0]++ + 1] == 'l' ? ll : l);
		i[0] = (fmt[i[0]] == 'l' ? i[0] + 1 : i[0]);
	}
	if (fmt[i[0]] == 'L')
	{
		zeus->flag = L;
		i[0]++;
	}
}

void	text(const char *fmt, char **str, size_t *i, t_mod *zeus)
{
	char	*ad;
	int		j;

	j = 0;
	ad = ft_strnew(0);
	while (fmt[i[0]] != '%' && fmt[i[0]] && j++ >= 0)
		add(&ad, fmt[i[0]++], 0);
	*str = strnnjoin(*str, ad, zeus->len, 0);
	zeus->len += j;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;
	char	*str;
	size_t	size;
	int		i;

	i = 0;
	ret = 0;
	va_start(ap, format);
	str = parser(ap, format, &ret);
	va_end(ap);
	size = ft_strlen(&str[ret]);
	ret = ret + size;
	write(1, str, ret);
	free(str);
	return (ret);
}
