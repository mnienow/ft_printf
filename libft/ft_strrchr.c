/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:20:17 by mnienow           #+#    #+#             */
/*   Updated: 2018/11/28 21:36:37 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i + 1)
	{
		if (s[i] != c)
			i--;
		else
			return ((char*)s + i);
	}
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
