/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:38:59 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/12 19:08:06 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *a;

	if (size + 1 < size)
		size--;
	if (!(a = malloc(++size)))
		return (NULL);
	while (size--)
		a[size] = '\0';
	return (a);
}
