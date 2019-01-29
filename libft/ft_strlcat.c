/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:11:35 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/03 20:39:34 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	j = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = (d > size ? s + size : s + d);
	if (d < size)
	{
		while (d + 1 < size && src[j])
		{
			dst[d] = src[j];
			d++;
			j++;
		}
		dst[d] = '\0';
	}
	return (i);
}
