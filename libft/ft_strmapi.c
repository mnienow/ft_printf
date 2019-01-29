/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:43:21 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/04 18:09:18 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;

	i = 0;
	if (!s || !f || !(a = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1)))
		return (NULL);
	while (s[i])
	{
		a[i] = f(i, (char)s[i]);
		i++;
	}
	a[i] = '\0';
	return ((char*)a);
}
