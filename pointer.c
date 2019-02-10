/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:37:58 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/01 16:41:47 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ftcount(long long int n)
{
	long long int i;
	
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

char	*ft_itoals(long long int nb)
{
	char	*str;
	int		len;
	long long int num;
	
	len = ftcount(nb) + 2;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (len > 2)
	{
		num =  nb % 16;
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

void	pointer(va_list ap, char **str)
{
	long long int	hex;
	char			*string;
	char			*tmp;

	hex = (long long int)va_arg(ap, void*);
	string = ft_itoals(hex);
	tmp = *str;
	*str = ft_strjoin(*str, string);
	free(tmp);
	free(string);
}

