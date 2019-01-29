/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:52:35 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/27 18:31:37 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *a;

	if (!(a = malloc(size)))
		return (NULL);
	while (size)
		a[--size] = 0;
	return (a);
}
