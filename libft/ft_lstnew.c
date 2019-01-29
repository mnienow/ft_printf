/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:23:26 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/09 22:21:13 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*cont;
	size_t	size;

	size = content_size;
	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if (!(cont = malloc(size)))
		{
			free(lst);
			return (NULL);
		}
		lst->content = ft_memcpy(cont, content, size);
		lst->content_size = size;
	}
	lst->next = NULL;
	return (lst);
}
