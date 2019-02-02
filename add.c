/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:12:19 by mnienow           #+#    #+#             */
/*   Updated: 2019/01/25 20:14:10 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count(int n)
{
	size_t	i;

	i = 0;
	if (!n || n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*char	*add(char *a, char b)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(ft_strlen(a) + 2);
	while (a[i])
	{
		ret[i] = a[i];
		i++;
	}
	ret[i++] = b;
	ret[i] = '\0';
	return (ret);
}*/

void	add(char **a, char b)
{
  char  *c;
  char  *tmp;
  
  c = malloc(2);
  c[0] = b;
  c[1] = '\0';
  tmp = *a;
  *a = ft_strjoin(*a, c);
  free(tmp);
  free(c);
}

