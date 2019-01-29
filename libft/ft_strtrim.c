/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:45:09 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/04 17:27:24 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*a;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	k = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[k] == 32 || s[k] == '\n' || s[k] == '\t')
		k--;
	if (s[i] == '\0')
		a = ft_strnew(0);
	else
	{
		if (!(a = (char*)malloc(k - i + 2)))
			return (NULL);
		while (s[i] && i <= k)
			a[j++] = s[i++];
		a[j] = '\0';
	}
	return (a);
}
