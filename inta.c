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
	tmp = ft_itoa(integer);
	tmp2 = *str;
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	free(tmp2);
}

size_t	ch(va_list ap, char **str)
{
	char	ch;
	size_t	ret;
	char	*tmp;

	ch = (char)va_arg(ap, int);
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
	{
		tmp = *str;
		add(str, ch);
		free(tmp);
	}
	return (ret);
}

void	ar(va_list ap, char **str)
{
	char *ar;
	char *tmp;

	if (!(ar = va_arg(ap, char*)))
	{
		tmp = *str;
		*str = ft_strjoin(*str, "(null)");
		free(tmp);
	}
	else
	{
		tmp = *str;
		*str = ft_strjoin(*str, ar);
		free(tmp);
	}

}
