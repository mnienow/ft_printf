/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:12:09 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/12 19:10:23 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static char	**mfree(char **a, size_t k, size_t i)
{
	if (k && k <= i)
	{
		while (--k)
			free(a[k]);
	}
	free(a[0]);
	free(a);
	a = NULL;
	return (a);
}

static char	**alstr(const char *s, char **a, char c, size_t i)
{
	size_t j;
	size_t k;

	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s)
		{
			j++;
			s++;
		}
		if (j > 0)
			if (!(a[k] = (char*)malloc(j + 1)))
				return (mfree(a, k, i));
		k++;
	}
	return (a);
}

static char	**instr(const char *s, char **a, char c)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != c && s[i])
		{
			a[k][j] = s[i];
			j++;
			i++;
		}
		if (j > 0)
			a[k][j] = '\0';
		k++;
	}
	k = (j > 0 ? k : --k);
	return (a);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	a = NULL;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			j++;
	}
	if (!(a = (char**)malloc(sizeof(char*) * j + 1)) || !alstr(s, a, c, j))
		return (NULL);
	instr(s, a, c);
	a[j] = 0;
	return (a);
}
