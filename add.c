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

char	*strnnjoin(char const *s1, char const *s2, size_t sz1, size_t sz2)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	sz1 = (sz1 == 0 ? ft_strlen(s1) : sz1);
	sz2 = (sz2 == 0 ? ft_strlen(s2) : sz2);
	if (!s1 || !s2 || !(a = (char*)malloc(sz1 + sz2 + 1)))
		return (NULL);
	while (i < sz1)
	{
		a[i] = s1[i];
		i++;
	}
	while (j < sz2)
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	return (a);
}

void	add(char **a, char b, size_t sz)
{
	char	*c;
	char	*tmp;

	c = malloc(2);
	c[0] = b;
	c[1] = '\0';
	tmp = *a;
	*a = strnnjoin(*a, c, sz, 1);
	free(tmp);
	free(c);
}
