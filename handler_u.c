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

static void	flag(t_mod *zeus, unsigned long long int *ui)
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
	size_t	sz;

	sz = ft_strlen(str);
	count = (i != 0 ? zeus->precision - sz : zeus->min_width - sz);
	if (count <= 0)
		return (str);
	str_zero = (char *)malloc(count + 1);
	str_zero[count] = '\0';
	while (--count >= 0)
		str_zero[count] = '0';
	tmp = str;
	str = ft_strjoin(str_zero, str);
	free(tmp);
	free(str_zero);
	return (str);
}

void		ft_udc(char **str, t_mod *zeus, va_list ap)
{
	unsigned long long int	ui;
	char					*strn;
	size_t					sz;

	ui = (unsigned long long int)va_arg(ap, unsigned long long int);
	flag(zeus, &ui);
	strn = ft_uitoal(ui, 10, zeus);
	if (zeus->precision != 1)
		strn = udc_precision(strn, zeus, 1);
	if (zeus->zero && !zeus->dot && zeus->min_width)
		strn = udc_precision(strn, zeus, 0);
	if (zeus->min_width > ft_strlen(strn))
		strn = udc_width(strn, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
