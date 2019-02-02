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

char	*spaces(int i)
{
	char *space;

	space = (char *)malloc(i + 1);
	while (space[--i])
		space[i] = ' ';
	return (space);
}

size_t	text(const char *format, char **str, size_t i)
{
	char	*ad;
	size_t	size;
	char	*tmp;
	int		j;

	size = ft_strlen(format);
	ad = ft_strnew(0);
	if (format[i] != '%')
	{
		while (format[i] != '%' && i < size)
			add(&ad, format[i++]);
		if ((j = ft_atoi(ad) != 0) && format[i] == '%')
			{
				tmp = ft_strdup("%");
				ad = spaces(j);
				ad = (j > 0 ? ft_strjoin(ad, tmp): ft_strjoin(tmp, ad));
				free(tmp);
				i++;
			}
	}
	tmp = *str;
	*str = ft_strjoin(*str, ad);
	free(tmp);
	free(ad);
	return (i);
}

void	ft_newflag(t_flag *flags)
{
	flags->h = 0;
	flags->l = 0;
	flags->hh = 0;
	flags->ll = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	size_t	ret;
	size_t	i;
	t_flag	flags;

	str = ft_strnew(0);
	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
<<<<<<< HEAD
=======
		{
			ft_newflag(flags);
>>>>>>> a20f1238980eca850ca649c8d53999dd0723c329
			i = text(format, &str, i);
		if (format[i++] == '%')
		{
			while (format[i] == ' ')
				i++;
			if (format[i] == '%')
			 	i++;
			ret = ret + percent(&format[i++], &str, ap);
																								//mb func(format, str, ap, ret);
		}
	}
	va_end(ap);
	ret = ret  + ft_strlen(str);
	write (1, str, ft_strlen(str));
	free(str);
	return (ret);
}
