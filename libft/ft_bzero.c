/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:54:57 by mnienow           #+#    #+#             */
/*   Updated: 2018/11/25 16:23:10 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			*((char*)s + i) = 0;
			i++;
		}
	}
}
