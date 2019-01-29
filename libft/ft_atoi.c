/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:11:11 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/09 21:38:45 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (res > ((res * 10) + ((str[i] - 48) % 10)))
			return ((sign == 1 ? -1 : 0));
		res = (res * 10) + ((str[i] - 48) % 10);
		i++;
	}
	return ((int)res * sign);
}
