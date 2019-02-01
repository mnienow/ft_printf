/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:06:03 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/01 12:06:06 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ftcount(int n)
{
	size_t i;
	
	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_itoal(int nb)
{
	char	*str;
	int		len;
	int 	num;
	
	len = ftcount(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		num = nb % 16;
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
		nb = nb / 16;
		len--;
	}
	return (str);
}

void	ft_hexadecimal(va_list ap, char **str)
{
	int		hex;
	char	*string;
	
	hex = va_arg(ap, int);
	string = ft_itoal(hex);
	*str = ft_strjoin(*str, string);
	free(string);
}
