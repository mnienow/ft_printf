/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:37:04 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/03 20:44:41 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[j + i])
	{
		while (haystack[j + i] != needle[i] && haystack[j + i] && needle[i])
			j++;
		while (haystack[j + i] == needle[i] && haystack[j + i] && needle[i])
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
