/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:22:52 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/03 21:17:37 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = dst;
	if (dst < src)
	{
		while (len--)
			*((char*)dst++) = *((char*)src++);
		return (temp);
	}
	else
	{
		while (len--)
			*((char*)dst + len) = *((char*)src + len);
	}
	return (dst);
}
