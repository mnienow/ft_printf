/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:21:42 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:47:22 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	inta(va_list ap, char **str)
{
	int		integer;
	char	*tmp;
	char	*tmp2;

	integer = va_arg(ap,int);
	tmp = *str;
	tmp2 = ft_itoa(integer);
	*str = ft_strjoin(*str, tmp2);
	free(tmp);
	free(tmp2);
}

size_t	ch(va_list ap, char **str)
{
	char	ch;
	int		ret;

	ch = (char)va_arg(ap, int);
	ret = ft_strlen(*str);
	if (ch == 0)
	{
		write (1, *str, ret);
		ret = ret + 1;
		write (1, "\0", 1);
	}
	*str = ft_strnew(0);
	return (ret);
}

void	ar(va_list ap, char **str)
{
	char *ar;

	if (!(ar = va_arg(ap, char*)))
		*str = ft_strjoin(*str, "(null)");
	else
		*str = ft_strjoin(*str, ar);
}
