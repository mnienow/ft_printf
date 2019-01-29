/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:44:36 by mnienow           #+#    #+#             */
/*   Updated: 2018/11/25 21:31:51 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char*)d++) = *((unsigned char*)s);
		if (*(unsigned char*)s++ == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
