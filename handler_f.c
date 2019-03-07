/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:38:04 by sstannis          #+#    #+#             */
/*   Updated: 2019/03/05 14:27:30 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		exp(int i)
{
	int			expt;

	expt = 10;
	while (i--)
		expt = expt * 10;
	return (expt);
}

void			ft_dbl(char **str, t_mod *zeus, va_list ap)
{
	double		nbr;
	int			prc;
	char		*strn;
	size_t		sz;

	prc = 6;
	if (zeus->precision > 0)
		prc = zeus->precision;
	nbr = (zeus->flag == 5 ? va_arg(ap, long double) : va_arg(ap, double));
	zeus->alpha = 0;
	strn = ft_itoal((int)nbr, 10, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
	nbr = (nbr - (int)nbr) * exp(prc - 1) + 0.5;
	*str = strnnjoin(*str, ft_strdup("."), zeus->len++, 0);
	strn = ft_itoal((int)nbr, 10, zeus);
	sz = ft_strlen(strn);
	*str = strnnjoin(*str, strn, zeus->len, 0);
	zeus->len += sz;
}
