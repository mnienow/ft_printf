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

static int	ftcount(int n, int base)
{
	int i;
	
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

char	*ft_itoal(long long int nb, int base)
{
	char	*str;
	int		len;
	long long int 	num;

	len = ftcount(nb, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % base;
		if (num == 10)
			str[len - 1] = 'a';
		else if (num == 11)
			str[len - 1] = 'b';
		else if (num == 12)
			str[len - 1] = 'c';
		else if (num == 13)
			str[len - 1] = 'd';
		else if (num == 14)
			str[len - 1] = 'e';
		else if (num == 15)
			str[len - 1] = 'f';
		else str[len - 1] = num + 48;
		nb = nb / base;
		len--;
	}
	return (str);
}
