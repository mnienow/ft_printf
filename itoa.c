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

	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (!nb && zeus->dot && !zeus->sharp)
		return (ft_strdup(""));
	sign = (nb < 0 ? 1 : 0);
	nb = ABS(nb);
	len = (ftcount(nb, base) + sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % base;
		if (num >= 10 && num <= 15)
			str[len-- - 1] = (zeus->alpha == 0 ? num + 87 : num + 55);
		else
			str[len-- - 1] = num + 48;
		nb = nb / base;
	}
	str[0] = (sign == 1 ? '-' : str[0]);
	return (str);
}

static int	uftcount(unsigned long long int n, int base)
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

char		*ft_uitoal(unsigned long long int nb, int base, t_mod *zeus)
{
	char					*str;
	int						len;
	unsigned long long int	num;

	if (!nb && zeus->dot && !zeus->sharp)
		return (ft_strdup(""));
	nb = ABS(nb);
	len = uftcount(nb, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % base;
		if (num >= 10 && num <= 15)
			str[len-- - 1] = (zeus->alpha == 0 ? num + 87 : num + 55);
		else
			str[len-- - 1] = num + 48;
		nb = nb / base;
	}
	return (str);
}
