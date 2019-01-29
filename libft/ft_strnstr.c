/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:10:41 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/02 15:14:39 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char*)haystack);
	while (haystack[j + i])
	{
		while (haystack[j + i] != needle[i] &&
				haystack[j + i] && needle[i] && j + i < len)
			j++;
		while (haystack[j + i] == needle[i] &&
				haystack[j + i] && needle[i] && j + i < len)
			i++;
		if (i != ft_strlen(needle) && haystack[j])
		{
			i = 0;
			j++;
		}
		if (i == ft_strlen(needle))
			return ((char*)haystack + j);
	}
	return (NULL);
}
