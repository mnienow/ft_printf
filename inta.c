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

char	*inta(va_list ap, char *str)
{
	int		integer;
	char	*tmp;
	char	*tmp2;

	integer = va_arg(ap,int);
	tmp = str;
	tmp2 = ft_itoa(integer);
	str = ft_strjoin(str, tmp2);
	free(tmp);
	free(tmp2);
	return (str);
}

char	*ch(va_list ap, char *str)
{
	char	ch;

	ch = (char)va_arg(ap, int);
	str = add(str, ch);
	return (str);
}

char	*ar(va_list ap, char *str)
{
	char *ar;

	ar = va_arg(ap, char*);
	str = ft_strjoin(str, ar);
	return (str);
}
