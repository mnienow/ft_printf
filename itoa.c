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

char		*ft_itoal(uintmax_t nb, int base, t_mod *zeus)
{
	char		*str;
	int			len;
	uintmax_t	num;

	len = ftcount(nb, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % base;
		if (num >= 10 && num <= 15)
		{
			if (zeus->alpha)
				str[len - 1] = num + 55;
			else
				str[len - 1] = num + 87;
		}
		else
			str[len - 1] = num + 48;
		nb = nb / base;
		len--;
	}
	return (str);
}
