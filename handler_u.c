/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:38:04 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/05 16:38:06 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag(t_mod *zeus, intmax_t *ui)
{
	if (!zeus->flag)
		*ui = (unsigned int)*ui;
	if (zeus->flag == 1)
		*ui = (unsigned short)*ui;
	if (zeus->flag == 2)
		*ui = (unsigned long)*ui;
	if (zeus->flag == 3)
		*ui = (unsigned char)*ui;
	if (zeus->flag == 4)
		*ui = (unsigned long long)*ui;
}

static char	*udc_width(char *str, t_mod *zeus)
{
	char	*str_spaces;
	char	*tmp;
	int		width;

	width = zeus->min_width - ft_strlen(str);
	str_spaces = (char *)malloc(sizeof(char) * (width + 1));
	str_spaces[width] = '\0';
	while (--width >= 0)
		str_spaces[width] = ' ';
	tmp = str;
	if (zeus->minus)
		str = ft_strjoin(str, str_spaces);
	else
		str = ft_strjoin(str_spaces, str);
	free(tmp);
	free(str_spaces);
	return (str);
}

static char	*udc_precision(char *str, t_mod *zeus, int i)
{
	char	*str_zero;
	char	*tmp;
	int		count;

	if (i)
		count = zeus->precision - ft_strlen(str);
	else
		count = zeus->min_width - ft_strlen(str);
	str_zero = (char *)malloc(sizeof(char) * (count + 1));
	str_zero[count] = '\0';
	while (--count >= 0)
		str_zero[count] = '0';
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

static char	*udc_sharp(char *str)
{
	char	*str_sharp;
	char	*tmp;

	str_sharp = ft_strdup("0x");
	tmp = str;
	str = ft_strjoin(str_sharp, str);
	free(tmp);
	free(str_sharp);
	return (str);
}

void		ft_udc(char **str, t_mod *zeus, va_list ap)
{
	intmax_t	ui;
	char		*strn;
	size_t		sz;

	ui = va_arg(ap, intmax_t);
	flag(zeus, &ui);
	strn = ft_itoal(ui, 10, zeus);
	if (zeus->precision)
		strn = udc_precision(strn, zeus, 1);
	if (zeus->sharp)
		strn = udc_sharp(strn);
	if (zeus->zero && !(zeus->precision) && zeus->min_width)
		strn = udc_precision(strn, zeus, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = udc_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
