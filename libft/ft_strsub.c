/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:04:30 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/06 22:21:11 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = (char*)malloc(sizeof(char) * len + 1)) ||
			!s || ft_strlen(&s[start]) < len)
		return (NULL);
	while (i < len)
	{
		a[i] = (char)s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
