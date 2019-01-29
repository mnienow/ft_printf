/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:16:19 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:38:03 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		count(int n)
{
	int i;

	i = 0;
	if (!n || n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		i;
	int		size;

	size = count(n);
	i = 0;
	if (!(a = (char*)ft_memalloc(size + 1)))
		return (NULL);
	if (n == -2147483648)
	{
		a = ft_strdup("-2147483648");
		return (a);
	}
	a[size] = '\0';
	if (n < 0 && ++i)
	{
		a[0] = '-';
		n = -n;
	}
	while (size-- != i)
	{
		a[size] = n % 10 + 48;
		n = n / 10;
	}
	return (a);
}
