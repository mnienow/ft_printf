/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:51:13 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/03 21:20:23 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (*((unsigned char*)s1 + i) == *((unsigned char*)s2 + i))
			i++;
		else
			break ;
	}
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
