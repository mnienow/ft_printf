/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:17:45 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/05 16:18:10 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftcount(uintmax_t n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoal(intmax_t nb, int base, t_mod *zeus)
{
	char		*str;
	int			len;
	uintmax_t	num;
	int			sign;

	sign = 0;
	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if ((nb == 0 && zeus->min_width != 0) ||
	(nb == 0 && zeus->dot && !zeus->sharp))
		return (ft_strdup(""));
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = (ftcount(nb, base) + sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % base;
		if (num >= 10 && num <= 15)
			str[len - 1] = (zeus->alpha == 0 ? num + 87 : num + 55);
		else
			str[len - 1] = num + 48;
		nb = nb / base;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
